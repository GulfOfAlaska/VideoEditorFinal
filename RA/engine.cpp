#include "engine.h"
#include "libsndfile/include/sndfile.hh"
#include <QProcess>
#include <QDebug>
#include <complex>
#include "fftw/fftw3.h"
#include <math.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <string.h>
#include <ap.h>
#include "alglibinternal.h"
#include "alglibmisc.h"
#include <alglibmisc.h>
#include <fasttransforms.h>



Engine::Engine()
{
}

int Engine::GetData()
{
    Engine::ConvertToWav(m_filepath);
    Engine::ReadWavFile();
    emit finished();
    return 0;
}

void Engine::DrawSpectogramFinished()
{
    qDebug()<<"Finished drawing spec";
}

int Engine::ConvertToWav(QString filepath)
{
    /* Use QProcess to execute the cmd syntax:
    ** "C:/FFmpeg/bin/ffmpeg.exe -y -i input output.wav"
    ** -y means to over-write the output
    ** which converts any media file into wav format
    */

    /* Sends a global signal tellin everyone that the engine is converting a wav file */
    emit processUpdate("Converting "+m_filepath+" to Wav format");

    QProcess * proc = new QProcess();
    /* Connect signal finished to slot ReadWaveFile()
    ** When conversion process finishes, read the output wav file
    ** Connect the signal and slot before the process starts
    */
    proc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<m_filepath<<"input.wav");
    proc->waitForFinished(-1);
    emit processUpdate("Done extracting audio");
    emit readFinished();
    qDebug()<<"done reading";
    return 0;
}

int Engine::ReadWavFile()
{
    emit processUpdate("Conversion ended, reading audio file.");
    /* Uses libsndfile to read the wav file and
     * store the sample data into a buffer */

    /* Open the WAV file. */
    info.format = 0;
    sf = sf_open("input.wav",SFM_READ,&info);
    if (sf == NULL)
    {
        qDebug()<< "Failed to open file";
        emit processUpdate("Failed to open file");
        exit(-1);
    }

    /* Initialise variables */
    f = info.frames;
    sr = info.samplerate;
    c = info.channels;
    num_items = f*c;
    seekable = info.seekable;
    audio_duration = f/double(sr); // in seconds

    /* Tells mainwindow to update the console with these outputs */
    emit processUpdate("Frames = " + QString::number(info.frames));
    emit processUpdate("SampleRate = " + QString::number(info.samplerate));
    emit processUpdate("Channels = " + QString::number(info.channels));
    emit processUpdate("NumItems = " + QString::number(num_items));
    emit processUpdate("Seekable = " + QString::number(info.seekable));
    emit processUpdate("Audio Length(seconds) = " + QString::number(audio_duration));

    qDebug()<<"audio duration"<<audio_duration;
    /*An item is a single sample of the data type you are reading;
    **ie a single short value for sf_read_short or a single float for sf_read_float.
    **For a sound file with only one channel, a frame is the same as a item (ie a single sample)
    **while for multi channel sound files, a single frame contains a single item for each channel
    */

    qDebug()<<f;
    qDebug()<<c;

    qDebug()<<"Closing File"<<seekable;
    /* Since wav = stereo,
     * Average out the left and right channels (Left + right)/2
     */

    // store data into storage
    if(m_mainOrSecondary == 1)
    {
        int digits = numDigits(num_items);
        int division = pow(10,digits/2);
        qDebug()<<"readsize: "<<f/division;
        /* Allocate space for the data to be read */
        temp_buf = (double *) malloc((f/division)*sizeof(double));
        audio_sampledata_buffer = (double *) malloc(f*sizeof(double));
        qDebug()<<"Read data from converted wav file";
        /* Read data from wav file */

        int count;
        int index=0;
       // out.open("test.txt");
        while (count=(sf_read_double(sf,temp_buf,(f/division))))
        {
            double average = 0.0;
            for (int i = 0; i < count; i += 2)
            {
                average+=temp_buf[i];
                average+=temp_buf[i+1];
                average = average/2.0;
                audio_sampledata_buffer[index]=average;
                //out<<average<<" ";
                index++;
            }
        }
       // out.close();

        qDebug()<<"Finished reading data"<<seekable;
        sf_close(sf);
        free(temp_buf);

        emit mainSWUpdate(audio_sampledata_buffer,f);
       m_datastorage->setMainBuffer(audio_sampledata_buffer);

        qDebug()<<"storing into main";
        m_datastorage->setMainBufferSize(f);
        m_datastorage->setMainNumFrame(f);
        m_datastorage->setMainSampleRate(sr);
    }
    else
    {
        /* Allocate space for the data to be read */
        temp_buf = (double *) malloc(num_items*sizeof(double));

        qDebug()<<"Read data from converted wav file";
        /* Read data from wav file */
        sf_read_double(sf,temp_buf,num_items);
        qDebug()<<"Finished reading data"<<seekable;
        sf_close(sf);
        qDebug()<<"Allocating buffer to average values";
        audio_sampledata_buffer = (double *) malloc(f*sizeof(double));
        int buf_index=0;
        qDebug()<<"Averaging values";
        for (int i = 0; i < num_items; i += 2)
        {
            double average = 0.0;
            for (int j = 0; j < 2; ++j)
            {
                average+=temp_buf[i+j];
            }
            average = average/2.0;
            audio_sampledata_buffer[buf_index]=average;
            buf_index++;
        }
        qDebug()<<"storing into secondary";
        m_datastorage->setSecondaryBuffer(audio_sampledata_buffer);
        m_datastorage->setSecondaryBufferSize(f);
        free(temp_buf);
    }

    /* Emit signal that sample data from wav file
     * has been read
     */
   // emit mainSWUpdate(audio_sampledata_buffer,f);

    /* Tells mainwindow to update main soundwave label */
    qDebug()<<"done reading";
    emit processUpdate("Done Reading");


    //    /* Tells mainwindow to update spectogram labels */
    //    if(m_mainOrSecondary==1)
    //    {
    //        emit mainSpgmUpdate(fftout,f/2);
    //    }
    //    else
    //    {
    //        emit secondarySpgmUpdate(fftout,f/2);
    //    }

    // free(audio_sampledata_buffer);
    /* free temporary buffer but not audio_sampledata_buffer(used by storage) */
    // emit readFinished();
    return 0;
}

//int Engine::ReadWavFile()
//{
//    emit processUpdate("Conversion ended, reading audio file.");
//    /* Uses libsndfile to read the wav file and
//     * store the sample data into a buffer */

//    /* Open the WAV file. */
//    info.format = 0;
//    sf = sf_open("input.wav",SFM_READ,&info);
//    if (sf == NULL)
//    {
//        qDebug()<< "Failed to open file";
//        emit processUpdate("Failed to open file");
//        exit(-1);
//    }

//    /* Initialise variables */
//    f = info.frames;
//    sr = info.samplerate;
//    c = info.channels;
//    num_items = f*c;
//    seekable = info.seekable;
//    audio_duration = f/double(sr); // in seconds

//    /* Tells mainwindow to update the console with these outputs */
//    emit processUpdate("Frames = " + QString::number(info.frames));
//    emit processUpdate("SampleRate = " + QString::number(info.samplerate));
//    emit processUpdate("Channels = " + QString::number(info.channels));
//    emit processUpdate("NumItems = " + QString::number(num_items));
//    emit processUpdate("Seekable = " + QString::number(info.seekable));
//    emit processUpdate("Audio Length(seconds) = " + QString::number(audio_duration));

//    qDebug()<<"audio duration"<<audio_duration;
//    /*An item is a single sample of the data type you are reading;
//    **ie a single short value for sf_read_short or a single float for sf_read_float.
//    **For a sound file with only one channel, a frame is the same as a item (ie a single sample)
//    **while for multi channel sound files, a single frame contains a single item for each channel
//    */

//    qDebug()<<f;
//    qDebug()<<c;
//    qDebug()<<"Allocating space for "<<num_items<<" data to be read";
//    /* Allocate space for the data to be read */
//    temp_buf = (double *) malloc(num_items*sizeof(double));

//    qDebug()<<"Read data from converted wav file";
//    /* Read data from wav file */
//    sf_read_double(sf,temp_buf,num_items);
//    qDebug()<<"Finished reading data"<<seekable;
//    sf_close(sf);

//    qDebug()<<"Closing File"<<seekable;
//    /* Since wav = stereo,
//     * Average out the left and right channels (Left + right)/2
//     */
//    qDebug()<<"Allocating buffer to average values";
//    audio_sampledata_buffer = (double *) malloc(f*sizeof(double));
//    int buf_index=0;
//    qDebug()<<"Averaging values";
//    for (int i = 0; i < num_items; i += 2)
//    {
//        double average = 0.0;
//        for (int j = 0; j < 2; ++j)
//        {
//            average+=temp_buf[i+j];
//        }
//        average = average/2.0;
//        audio_sampledata_buffer[buf_index]=average;
//        buf_index++;
//    }

//    // store data into storage
//    if(m_mainOrSecondary == 1)
//    {
//        qDebug()<<"storing into main";
//        m_datastorage->setMainBuffer(audio_sampledata_buffer);
//        m_datastorage->setMainBufferSize(f);
//        m_datastorage->setMainNumFrame(f);
//        m_datastorage->setMainSampleRate(sr);

//    }
//    else
//    {
//        qDebug()<<"storing into secondary";
//        m_datastorage->setSecondaryBuffer(audio_sampledata_buffer);
//        m_datastorage->setSecondaryBufferSize(f);
//    }

//    /* Emit signal that sample data from wav file
//     * has been read
//     */
//    emit mainSWUpdate(audio_sampledata_buffer,f);

//    /* Tells mainwindow to update main soundwave label */
//    qDebug()<<"done reading";
//    emit processUpdate("Done Reading");


//    //    /* Tells mainwindow to update spectogram labels */
//    //    if(m_mainOrSecondary==1)
//    //    {
//    //        emit mainSpgmUpdate(fftout,f/2);
//    //    }
//    //    else
//    //    {
//    //        emit secondarySpgmUpdate(fftout,f/2);
//    //    }

//    // free(audio_sampledata_buffer);
//    /* free temporary buffer but not audio_sampledata_buffer(used by storage) */
//    free(temp_buf);
//    emit readFinished();
//    return 0;
//}

void Engine::SearchAudio()
{
    qDebug()<<"searching audio";
    /* Variables */
    double* sec_buf = m_datastorage->getSecondaryBuffer();
    int sec_buf_size = m_datastorage->getSecondaryBufferSize();
    double *temp_main_buf = m_datastorage->getMainBuffer();
    double *main_buf = (double *) malloc(sec_buf_size*sizeof(double));
    int main_buf_size = m_datastorage->getMainBufferSize();
    unsigned long long int main_buf_index = 0;
    int sample_rate = m_datastorage->getMainSampleRate();
    bool inSegment = false;
    unsigned long long int segmentStartTime = 0;
    unsigned long long int segmentEndTime = 0;
    double criteria = 0.9;
    int maxCrossCorrelationIndex = 0;

    qDebug()<<"main_buf_size: "<<main_buf_size;
    qDebug()<<"sec_buf_size: "<<sec_buf_size;
    while(main_buf_index < main_buf_size-sec_buf_size+1)
    {
        qDebug()<<"slicing";
        /* Slice the main audio into pieces the size of the secondary audio */
        int remaining = main_buf_size-1-main_buf_index;
        for(int i=0; i<sec_buf_size;i++)
        {
            if(i<remaining)
            {
                main_buf[i] = temp_main_buf[main_buf_index+i];
            }
            else
            {
                main_buf[i] = 0;
            }
        }

        /* Perform cross correlation */
        alglib::real_1d_array sec_signal;
        sec_signal.setcontent(sec_buf_size,sec_buf);

        alglib::real_1d_array main_signal;
        main_signal.setcontent(sec_buf_size,main_buf);

        alglib::real_1d_array corrResult;
        corrResult.setlength(sec_buf_size + sec_buf_size-2);
        alglib::corrr1d(main_signal, sec_buf_size, sec_signal, sec_buf_size, corrResult);

        /* Get max value of correlation results */
        double max=0.0;
        for(int i=0;i<corrResult.length();i++)
        {
            if(corrResult[i]> max)
            {
                maxCrossCorrelationIndex=i;
                max = corrResult[i];
            }
        }

        /* Calculate the mean of the two series x[], y[] */
        double mean_main = 0;
        double mean_secondary = 0;
        for (int i=0;i<sec_buf_size;i++) {
            mean_main += main_signal[i];
            mean_secondary += sec_signal[i];
        }
        mean_main/= sec_buf_size;
        mean_secondary /= sec_buf_size;

        /* Calculate the denominator */
        double sx = 0;
        double sy = 0;
        for (int i=0;i<sec_buf_size;i++) {
            sx += (main_signal[i] - mean_main) * (main_signal[i] - mean_main);
            sy += (sec_signal[i] - mean_secondary) * (sec_signal[i] - mean_secondary);
        }
        double denom = sqrt(sx*sy);

        /* Calcualte the coefficient */
        qDebug()<<"max: "<<max;
        double coefficient = max/denom;

        /* If not part of segment & coefficient below criteria, carry on searching */
        /* If part of segment &  coefficient below criteria, end segment & save end timing as last searched time
             * And update search table */
        qDebug()<<"coefficient: "<<coefficient;
        if((inSegment==true && coefficient<criteria)||(inSegment==true && (main_buf_index+sample_rate/2>main_buf_size-sec_buf_size+1)))
        {
            qDebug()<<"exited segment";
            if(main_buf_index+sample_rate/2>main_buf_size-sec_buf_size+1)
            {
                segmentEndTime=(((main_buf_size-1)*1000)/sample_rate);
            }
            else
            {
                segmentEndTime=((main_buf_index*1000)/sample_rate);
            }

             qDebug()<<"segmentEndTime:  "<<segmentEndTime;

            int end_hr = segmentEndTime/(1000*60*60);
            int end_min = (segmentEndTime/(1000*60))%60;
            int end_sec = (segmentEndTime/(1000))%60;
            int end_milisec = segmentEndTime % 1000;
            QString end_time = QString::number(end_hr)+":"+QString::number(end_min)+":"+QString::number(end_sec)+"."+QString::number(end_milisec);

            int start_hr = segmentStartTime/(1000*60*60);
            int start_min = (segmentStartTime/(1000*60))%60;
            int start_sec = (segmentStartTime/(1000))%60;
            int start_milisec = segmentStartTime % 1000;
            QString start_time = QString::number(start_hr)+":"+QString::number(start_min)+":"+QString::number(start_sec)+"."+QString::number(start_milisec);

            trimDetail *trim_detail = new trimDetail;
            trim_detail->setName("");
            trim_detail->setStartTime(segmentStartTime);
            trim_detail->setEndTime(segmentEndTime);
            trim_detail->setStartTimeText(start_time);
            trim_detail->setEndTimeText(end_time);
            m_datastorage->addAudioSearchResult(trim_detail);
            inSegment=false;
            emit updateAudioSearchTable();
        }
        /* If part of segment & coefficient above criteria, carry on searching */
        else if(inSegment==true && coefficient>criteria)
        {

        }
        /* If not part of segment & coefficient above criteria, mark as start of a segment */
        else if(inSegment==false && coefficient>criteria)
        {
            qDebug()<<"entered segment";
            segmentStartTime=((main_buf_index*1000)/sample_rate);
            qDebug()<<"segmentStartTime:  "<<segmentStartTime;
            qDebug()<<"main_buf_index: "<<main_buf_index*1000;

            inSegment=true;
        }

        /* Increment audio by 1/2 of a second*/
        main_buf_index+=sample_rate/2;
    }
    qDebug()<<"done searching";
    free(main_buf);



//    int main_buf_index = 0;
//    int window_size = m_datastorage->getSecondaryBufferSize(); // Set fft window size to size of secondary audio clip
//    int main_audio_buffer_size = m_datastorage->getMainBufferSize(); // Get size of buffer of main audio
//    int sample_rate = m_datastorage->getMainSampleRate();

//    qDebug()<<window_size;
//    qDebug()<<main_audio_buffer_size;
//    /* Perform fft on secondary audio first */
//    /* Allocate space for results of hannings window function
//         *  Zero-pad (allocate 2*itemnum-1 space and put zeros for empty slots ) before fft
//         */
//    double* secondary_hanning_results_buffer = (double *) malloc((window_size*2)*sizeof(double));

//    qDebug()<<"Applying hw function to secondary clip";
//    /* Apply hannings window function to secondary clip to smoothen out distortion */
//    double* sec_buf = m_datastorage->getSecondaryBuffer();
//    for (int i = 0; i < ((window_size*2)); i++)
//    {
//        if(i<window_size)
//        {
//            double multiplier = 0.5 * (1 - cos(2*PI*i/(window_size-1))); // Hannings function
//            secondary_hanning_results_buffer[i]= multiplier * sec_buf[i];
//        }
//        else
//        {
//            secondary_hanning_results_buffer[i]=0; // Zero padding
//        }
//    }

//    qDebug()<<"ffting secondary audio data";
//    /* Perform FFT on secondary audio data */
//    fftw_complex* secondary_fft_results_buffer = (fftw_complex *) malloc((window_size*2)*sizeof(double));
//    p_secondary = fftw_plan_dft_r2c_1d((window_size*2), secondary_hanning_results_buffer, secondary_fft_results_buffer,FFTW_ESTIMATE);
//    fftw_execute(p_secondary);
//    emit secondarySpgmUpdate(secondary_fft_results_buffer,f/2);

//    /* Get magnitude values of fft results */
//    double* sec_buf_mag = (double *) malloc((window_size*2)*sizeof(double));
//    for(int i=0;i<window_size*2;i++)
//    {
//        sec_buf_mag[i] = sqrt( secondary_fft_results_buffer[i][0]*secondary_fft_results_buffer[i][0]+secondary_fft_results_buffer[i][1]*secondary_fft_results_buffer[i][1]);
//    }

//    fftw_free(secondary_fft_results_buffer);
//    qDebug()<<"ffting main audio data ";
//    /* Split main audio data into size of secondary clip for more efficient FFT & comparison */
//    double *main_buf = m_datastorage->getMainBuffer();

//    while(main_buf_index < main_audio_buffer_size - window_size)
//    {
//        /* Allocate space (zero-pad) for results of hannings window function */
//        double* main_buf_hanning_result = (double *) malloc((window_size*2)*sizeof(double));

//        /* Apply hannings window function to smoothen out distortion */
//        for (int i = 0; i < (window_size*2); i++)
//        {
//            if(i<window_size)
//            {
//                double multiplier = 0.5 * (1 - cos(2*PI*i/(window_size-1))); // Hannings function
//                main_buf_hanning_result[i]= multiplier * main_buf[i];
//            }
//            else
//            {
//                main_buf_hanning_result[i]=0; // Zero padding
//            }
//        }

//        /* Allocate space for fft results */
//        fftw_complex* main_fft_results_buffer = (fftw_complex *) malloc((window_size*2)*sizeof(fftw_complex));

//        /* Perform FFT */
//        p_main = fftw_plan_dft_r2c_1d((window_size*2), main_buf_hanning_result, main_fft_results_buffer,FFTW_ESTIMATE);
//        fftw_execute(p_main);

//        /* Get complex magnitude for both fft results */
//        double* main_buf_mag = (double *) malloc((window_size*2)*sizeof(double));
//        for(int i=0;i<window_size*2;i++)
//        {
//            main_buf_mag[i] = sqrt( main_fft_results_buffer[i][0]* main_fft_results_buffer[i][0] +  main_fft_results_buffer[i][1]* main_fft_results_buffer[i][1]);
//        }


//        /* Perform cross correlation */
//        /* Calculate the mean of the two series x[], y[] */
//        double mean_main = 0;
//        double mean_secondary = 0;
//        for (int i=0;i<window_size;i++)
//        {
//            mean_main += main_buf_mag[i];
//            mean_secondary += sec_buf_mag[i];
//        }
//        mean_main/= window_size;
//        mean_secondary /= window_size;

//        /* Calculate the denominator */
//        double sx = 0;
//        double sy = 0;
//        for (int i=0;i<window_size;i++)
//        {
//            sx += (main_buf_mag[i] - mean_main) * (main_buf_mag[i] - mean_main);
//            sy += (sec_buf_mag[i] - mean_secondary) * (sec_buf_mag[i] - mean_secondary);
//        }
//        double denom = sqrt(sx*sy);


//        /* Calculate the correlation series */
//        int delay=0;
//        int maxdelay=window_size;
//        double sxy;
//        int j;

//        for (delay=-maxdelay;delay<maxdelay;delay++)
//        {
//           sxy = 0;
//           for (int i=0;i<window_size;i++)
//           {
//              j = i + delay;
//              if (j < 0 || j >= window_size)
//                 continue;
//              else
//                 sxy += (main_buf_mag[i] - mean_main) * (sec_buf_mag[i] - mean_secondary);
//              /* Or should it be (?)
//              if (j < 0 || j >= n)
//                 sxy += (x[i] - mx) * (-my);
//              else
//                 sxy += (x[i] - mx) * (y[j] - my);
//              */
//           }
//           double r = sxy / denom;

//           /* r is the correlation coefficient at "delay" */


//        /* Increment buf_index (0.5 secs) */
//        main_buf_index += (sample_rate/2);

//        /* Free buffers */



//        }

//    /* Destroy fftw plan */

//    /* Normalize the values back to the orignal range of values
//         * by diving the values by number of items
//         */
//    }
}

QString Engine::GetRandomString(int length)
{
    const QString possibleCharacters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");

    QString randomString;
    for(int i=0; i<length; ++i)
    {
        int index = qrand() % possibleCharacters.length();
        QChar nextChar = possibleCharacters.at(index);
        randomString.append(nextChar);
    }
    return randomString;
}

void Engine::exportVideo()
{
    exportMutes();
    exportTrims();
    emit processUpdate("Done Exporting");
}

void Engine::exportTrims()
{
    qDebug()<<"export trim triggered";
    std::vector <trimDetail*> trim_list = m_datastorage->getTrimList();

    int total_trims = trim_list.size();
    int remaining_trims = total_trims;
    int trim_index = 0;
    bool first_cut = true;
    QString prevEndText = "00:00:00";
    int prevEnd = 0;
    int main_video_duration = m_datastorage->getMainVideoDuration();
    int hr = main_video_duration/(1000*60*60);
    int min = (main_video_duration/(1000*60))%60;
    int sec = (main_video_duration/(1000))%60;
    int milisec = main_video_duration % 1000;
    QString main_video_duration_text = QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(milisec);
    qDebug()<<"total trims: "<<total_trims;
    while(total_trims>0)
    {
        /* Calculate remaining trims */
        remaining_trims = total_trims-1;

        /* Get start and end of trimmed part */
        QString curStartText = trim_list[trim_index]->getStartTimeText();
        QString curEndText = trim_list[trim_index]->getEndTimeText();
        int curEnd = trim_list[trim_index]->getEndTime();

        qDebug()<<"previousEndTime: "<<prevEnd;

        /* Cut from prevEnd to curStart */
        if(first_cut==true)
        {
            cutVideo(prevEndText,curStartText,"mainExport.mp4");
        }
        else
        {
            cutVideo(prevEndText,curStartText,"secExport.mp4");
            concatenateVideo("mainExport.mp4","secExport.mp4","mainExport.mp4");
        }

        total_trims-=1;
        trim_index+=1;
        prevEndText=curEndText;
        prevEnd=curEnd;
        first_cut=false;
    }

    /* Concatenate with end of video */
    if(prevEnd!=main_video_duration  && trim_list.size()>0 )
    {
        cutVideo(prevEndText,main_video_duration_text,"secExport.mp4");
        concatenateVideo("mainExport.mp4","secExport.mp4","finalProduct.mp4");
        m_filepath="finalProduct.mp4";
    }


}

void Engine::exportMutes()
{
    qDebug()<<"export mute triggered";
    std::vector <trimDetail*> mute_list = m_datastorage->getMuteList();

    int total_mutes = mute_list.size();
    int remaining_mutes = total_mutes;
    int mute_index = 0;
    bool first_cut = true;
    QString prevEndText = "00:00:00";
    int prevEnd = 0;
    int main_video_duration = m_datastorage->getMainVideoDuration();
    int hr = main_video_duration/(1000*60*60);
    int min = (main_video_duration/(1000*60))%60;
    int sec = (main_video_duration/(1000))%60;
    int milisec = main_video_duration % 1000;
    QString main_video_duration_text = QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(milisec);
qDebug()<<"total mutess: "<<total_mutes;
    while(total_mutes>0)
    {
        /* Calculate remaining trims */
        remaining_mutes = total_mutes-1;

        /* Get start and end of trimmed part */
        QString curStartText = mute_list[mute_index]->getStartTimeText();
        QString curEndText = mute_list[mute_index]->getEndTimeText();
        int curEnd =  mute_list[mute_index]->getEndTime();

        qDebug()<<"previousEndTime: "<<prevEnd;

        /* Cut from prevEnd to curStart */
        if(first_cut==true)
        {
            cutVideo(prevEndText,curStartText,"muteExportA.mp4");
            cutVideo(curStartText,curEndText,"toBeMuted.mp4");
            muteVideo("toBeMuted.mp4","muted.mp4");
            concatenateVideo("muteExportA.mp4","muted.mp4","mainMuteExport.mp4");
        }
        else
        {
            cutVideo(prevEndText,curStartText,"secMuteExportA.mp4");
            cutVideo(curStartText,curEndText,"toBeMuted.mp4");
            muteVideo("toBeMuted.mp4","muted.mp4");
            concatenateVideo("muted.mp4","secMuteExportA.mp4","secMuteExportB.mp4");
            concatenateVideo("mainMuteExport.mp4","secMuteExportB.mp4","mainMuteExport.mp4");
        }

        total_mutes-=1;
        mute_index+=1;
        prevEndText=curEndText;
        prevEnd=curEnd;
        first_cut=false;
    }

    /* Concatenate with end of video */
    if(prevEnd!=main_video_duration && mute_list.size()>0)
    {
        cutVideo(prevEndText,main_video_duration_text,"secMuteExport.mp4");
        concatenateVideo("mainMuteExport.mp4","secMuteExport.mp4","finalProduct.mp4");
    }
}

void Engine::muteVideo( QString input_file,QString output_file)
{
    QProcess * cutProc = new QProcess();

    /*ffmpeg -y -i video.mp4 -an mute-video.mp4*/
    cutProc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<input_file<<"-an"<<output_file);

    /* Wait for process to finish */
    cutProc->waitForFinished(-1);
    qDebug()<<"finished muting";
}

void Engine::cutVideo(QString start_time, QString end_time, QString output_file)
{
    QProcess * cutProc = new QProcess();
    QString filepath = m_filepath;

    qDebug()<<"filepath: "<<m_filepath;
    qDebug()<<"cutstart: "<<start_time;
    qDebug()<<"cutend: "<<end_time;
    qDebug()<<"output: "<<output_file;

    /* ffmpeg -y -i movie.mp4 -ss 00:00:03 -to 00:00:08 -async 1 cut.mp4 */
    cutProc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<filepath<<"-ss"<<start_time<<"-to"<<end_time<<"-async"<<"1"<<output_file);

    /* Wait for process to finish */
    cutProc->waitForFinished(-1);
    qDebug()<<"finished cutting";
}

void Engine::concatenateVideo(QString start_video, QString end_video, QString output_file)
{
    qDebug()<<"concatenating";
    qDebug()<<"output: "<<output_file;
    /* concatenate the cut clip with the main export clip
    echo "file 'clip1.mkv'" > concat.txt
    echo "file 'clip2.mkv'" >> concat.txt
    ffmpeg -f concat -i concat.txt -codec copy output.mkv */

    QProcess * cutProc = new QProcess();

    std::ofstream shitfile ("concat.txt");
    shitfile<<"file \'"<<start_video.toStdString()<<"\' \n";
    shitfile<<"file \'"<<end_video.toStdString()<<"\' \n";
    shitfile.close();

    /* ffmpeg -f concat -i concat.txt -codec copy output.mkv */
    cutProc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-f"<<"concat"<<"-y"<<"-i"<<"concat.txt"<<"-codec"<<"copy"<<output_file);

    /* Wait for process to finish */
    cutProc->waitForFinished(-1);
}

void Engine::insertVideo(QString start_time_text, int start_time, int clip_duration, QString clip_filepath)
{
    qDebug()<<"entered insert: "<<m_filepath;
    int main_video_duration = m_datastorage->getMainVideoDuration();
    int hr = main_video_duration/(1000*60*60);
    int min = (main_video_duration/(1000*60))%60;
    int sec = (main_video_duration/(1000))%60;
    int milisec = main_video_duration % 1000;
    QString main_video_duration_text = QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(milisec);

    /* Convert clip to mp4 */
    QProcess * proc = new QProcess();
    proc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<clip_filepath<<"insertClip.mp4");
    proc->waitForFinished(-1);

    /* Cut from beginning to start_time (clip a) */
    cutVideo("0:0:0",start_time_text,"insertClipA.mp4");
    /* Cut from start_time to end (clip b) */
    cutVideo(start_time_text,main_video_duration_text,"insertClipB.mp4");
    /* Concatenate a with inserted clip (clip c) */
    concatenateVideo("insertClipA.mp4","insertClip.mp4","insertClipC.mp4");
    if(start_time=0)
    {
        /* Concatenate c with b (clip d)*/
        concatenateVideo("insertClip.mp4","insertClipB.mp4","joinResult.mp4");
    }
    if(start_time = main_video_duration)
    {
        /* Concatenate b with clip (clip d)*/
        concatenateVideo("insertClipB.mp4","insertClip.mp4","joinResult.mp4");
    }
    if(start_time!=0 && start_time!=main_video_duration)
    {
        /* Concatenate c with b (clip d)*/
        concatenateVideo("insertClipC.mp4","insertClipB.mp4","joinResult.mp4");
    }


    /* Increase timing of all trims after insert start_time */
    m_datastorage->increaseTrimTime(clip_duration,start_time);
    /* Insert timing of all joins after insert start_time */
    m_datastorage->increaseJoinTime(clip_duration,start_time);
    /* Increase timing of all mutes after insert start_time */
    m_datastorage->increaseMuteTime(clip_duration,start_time);
}

void Engine::undoInsertVideo(int join_list_index)
{
    std::vector <trimDetail*> join_list = m_datastorage->getJoinList();
    int duration_to_reduce = join_list[join_list_index]->getDuration()*(-1);
    int main_video_duration = m_datastorage->getMainVideoDuration();
    int hr = main_video_duration/(1000*60*60);
    int min = (main_video_duration/(1000*60))%60;
    int sec = (main_video_duration/(1000))%60;
    int milisec = main_video_duration % 1000;
    int after_this_time = join_list[join_list_index]->getStartTime();
    QString main_video_duration_text = QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(milisec);
    QString start_time_to_cut = join_list[join_list_index]->getStartTimeText();
    QString end_time_to_cut = join_list[join_list_index]->getEndTimeText();
    int clip_start_time = join_list[join_list_index]->getStartTime();

    /*Cut from start to start_time_to_cut (clip a) */
    cutVideo("0:0:0",start_time_to_cut,"undoJoinA.mp4");

    if(clip_start_time == 0)
    {
        /*Cut from  end_time_to_cut to main_video_duration (clip b) */
        cutVideo(end_time_to_cut,main_video_duration_text,"undonejoinResult.mp4");
    }

    if(clip_start_time == main_video_duration)
    {
        /*Cut from  end_time_to_cut to main_video_duration (clip b) */
        cutVideo("0:0:0",start_time_to_cut,"undonejoinResult.mp4");
    }

     if(clip_start_time != main_video_duration && clip_start_time!= 0)
     {
         /*Cut from  end_time_to_cut to main_video_duration (clip b) */
         cutVideo("0:0:0",start_time_to_cut,"undoJoinA.mp4");

         /* Concatenate clip a and clip b */
         concatenateVideo("undoJoinA.mp4","undoJoinB.mp4","undonejoinResult.mp4");
     }


    /* Decrease timing of all trims after insert start_time */
    m_datastorage->increaseTrimTime(duration_to_reduce,after_this_time);
    /* Decrease timing of all joins after insert start_time */
    m_datastorage->increaseJoinTime(duration_to_reduce,after_this_time);
    /* Decrease timing of all mutes after insert start_time */
    m_datastorage->increaseMuteTime(duration_to_reduce,after_this_time);
}

int Engine::numDigits(int num)
{
    int digits = 0;
    if (num < 0) digits = 1;
    while (num)
    {
        num /= 10;
        digits++;
    }
    return digits;
}
