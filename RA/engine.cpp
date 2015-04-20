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
    emit finished();
    return 0;
}

void Engine::DrawSpectogramFinished()
{
    qDebug()<<"Finished drawing spec";
}

int Engine::ConvertToWav(QString filepath)
{
    QString output;

    if(m_mainOrSecondary==1)
    {
        output = "MainInput.wav";
    }
    else
    {
        output = "SecondaryInput.wav";
    }

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
    proc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<m_filepath<<output);
    proc->waitForFinished(-1);
    emit processUpdate("Done extracting audio");
    emit readFinished();
    qDebug()<<"done reading";
    return 0;
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
    bool cut_from_start = false;
    int main_export_num = 0;
    while(total_trims>0)
    {
        /* Calculate remaining trims */
        remaining_trims = total_trims-1;

        /* Get start and end of trimmed part */
        QString curStartText = trim_list[trim_index]->getStartTimeText();
        int curStartTime = trim_list[trim_index]->getStartTime();
        QString curEndText = trim_list[trim_index]->getEndTimeText();
        int curEnd = trim_list[trim_index]->getEndTime();


        qDebug()<<"previousEndTime: "<<prevEnd;

        /* Cut from prevEnd to curStart */
        if(first_cut==true)
        {
            if(curStartTime==0)
            {
                cut_from_start=true;
                qDebug()<<"cut from start";
            }
            else
            {
                cutVideo(prevEndText,curStartText,QString::number(main_export_num)+"mainTrimExport.mp4");
            }
        }
        else
        {
            if(cut_from_start==true)
            {
                qDebug()<<"cut from start true";
                cutVideo(prevEndText,curStartText,QString::number(main_export_num)+"mainTrimExport.mp4");
                cut_from_start=false;
            }
            else
            {
                cutVideo(prevEndText,curStartText,"secTrimExport.mp4");
                concatenateVideo(QString::number(main_export_num)+"mainTrimExport.mp4","secTrimExport.mp4",QString::number(main_export_num+1)+"mainTrimExport.mp4");
                main_export_num++;
            }
        }

        total_trims-=1;
        trim_index+=1;
        prevEndText=curEndText;
        prevEnd=curEnd;
        first_cut=false;
    }

    /* Concatenate with end of video */
    if(prevEnd!=main_video_duration  && trim_list.size()>1 )
    {
        cutVideo(prevEndText,main_video_duration_text,"secTrimExport.mp4");
        concatenateVideo(QString::number(main_export_num)+"mainTrimExport.mp4","secTrimExport.mp4","finalProduct.mp4");
        m_filepath="finalProduct.mp4";
    }

    if(prevEnd!=main_video_duration  && trim_list.size()==1 && cut_from_start==true )
    {
        cutVideo(prevEndText,main_video_duration_text,"finalProduct.mp4");
    }

    /* Take into account trims that reach the end of the video */
    if(prevEnd==main_video_duration  && trim_list.size()>0)
    {
        QProcess * proc = new QProcess();
        /* Connect signal finished to slot ReadWaveFile()
        ** When conversion process finishes, read the output wav file
        ** Connect the signal and slot before the process starts
        */
        proc->start("C:/FFmpeg/bin/ffmpeg.exe",QStringList()<<"-y"<<"-i"<<QString::number(main_export_num)+"mainTrimExport.mp4"<<"finalProduct.mp4");
        proc->waitForFinished(-1);
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
    qDebug()<<"concatenating "<<start_video<<end_video;
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

void Engine::insertVideo()
{
    QString start_time_text = m_insert_start_time_text;
    int start_time = m_insert_start_time;
    int clip_duration = m_insert_clip_duration;
    QString clip_filepath = m_insert_clip_filepath;


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
    if(start_time==0)
    {
        /* Concatenate c with b (clip d)*/
        concatenateVideo("insertClip.mp4","insertClipB.mp4",QString::number(m_insert_number)+"joinResult.mp4");
    }
    if(start_time == main_video_duration)
    {
        /* Concatenate b with clip (clip d)*/
        concatenateVideo("insertClipB.mp4","insertClip.mp4",QString::number(m_insert_number)+"joinResult.mp4");
    }
    if(start_time!=0 && start_time!=main_video_duration)
    {
        /* Concatenate c with b (clip d)*/
        concatenateVideo("insertClipC.mp4","insertClipB.mp4",QString::number(m_insert_number)+"joinResult.mp4");
    }

    /* Increase timing of all trims after insert start_time */
    m_datastorage->increaseTrimTime(clip_duration,start_time);
    /* Insert timing of all joins after insert start_time */
    m_datastorage->increaseJoinTime(clip_duration,start_time);
    /* Increase timing of all mutes after insert start_time */
    m_datastorage->increaseMuteTime(clip_duration,start_time);

    emit insertFinished();
}

void Engine::undoInsertVideo()
{
    std::vector <trimDetail*> join_list = m_datastorage->getJoinList();
    std::vector <trimDetail*> trim_list = m_datastorage->getTrimList();
    std::vector <trimDetail*> mute_list = m_datastorage->getMuteList();
    int duration_to_reduce = join_list[join_list.size()-1]->getDuration()*(-1);
    int main_video_duration = m_datastorage->getMainVideoDuration();
    int hr = main_video_duration/(1000*60*60);
    int min = (main_video_duration/(1000*60))%60;
    int sec = (main_video_duration/(1000))%60;
    int milisec = main_video_duration % 1000;
    int after_this_time = join_list[join_list.size()-1]->getStartTime();
    int join_start_time = join_list[join_list.size()-1]->getStartTime();
    int join_end_time = join_list[join_list.size()-1]->getEndTime();
    QString main_video_duration_text = QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+"."+QString::number(milisec);
    QString start_time_to_cut = join_list[join_list.size()-1]->getStartTimeText();
    QString end_time_to_cut = join_list[join_list.size()-1]->getEndTimeText();
    int clip_start_time = join_list[join_list.size()-1]->getStartTime();

    /*Cut from start to start_time_to_cut (clip a) */
    cutVideo("0:0:0",start_time_to_cut,"undoJoinA.mp4");

    if(clip_start_time == 0)
    {
        /*Cut from  end_time_to_cut to main_video_duration (clip b) */
        cutVideo(end_time_to_cut,main_video_duration_text,QString::number(m_undo_insert_number)+"undonejoinResult.mp4");
    }

    if(clip_start_time == main_video_duration)
    {
        /*Cut from  end_time_to_cut to main_video_duration (clip b) */
        cutVideo("0:0:0",start_time_to_cut,QString::number(m_undo_insert_number)+"undonejoinResult.mp4");
    }

    if(clip_start_time != main_video_duration && clip_start_time!= 0)
    {
        /*Cut from  end_time_to_cut to main_video_duration (clip b) */
        cutVideo(end_time_to_cut,main_video_duration_text,"undoJoinB.mp4");

        /* Concatenate clip a and clip b */
        concatenateVideo("undoJoinA.mp4","undoJoinB.mp4",QString::number(m_undo_insert_number)+"undonejoinResult.mp4");
    }

    /* Decrease timing of all trims after insert start_time */
    m_datastorage->increaseTrimTime(duration_to_reduce,after_this_time);
    /* Decrease timing of all joins after insert start_time */
    m_datastorage->increaseJoinTime(duration_to_reduce,after_this_time);
    /* Decrease timing of all mutes after insert start_time */
    m_datastorage->increaseMuteTime(duration_to_reduce,after_this_time);

    for(int i=0;i<mute_list.size();i++)
    {
       if(mute_list[i]->getStartTime>join_start_time && mute_list[i]->getStartTime<join_end_time)
       {
           m_datastorage->deleteMuteDetails(i);
       }
       if(mute_list[i]->getEndTime>join_start_time && mute_list[i]->getEndTime<join_end_time)
       {
           m_datastorage->deleteMuteDetails(i);
       }
    }

    for(int i=0;i<trim_list.size();i++)
    {
        if(trim_list[i]->getStartTime>join_start_time && trim_list[i]->getStartTime<join_end_time)
        {
            m_datastorage->deleteTrimDetails(i);
        }
        if(trim_list[i]->getEndTime>join_start_time && trim_list[i]->getEndTime<join_end_time)
        {
            m_datastorage->deleteTrimDetails(i);
        }
    }

    m_datastorage->deleteJoinDetails(join_list.size()-1);

    emit undoInsertFinished();
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



void Engine::SearchAudio()
{
    emit processUpdate("Search started");
    emit processUpdate("Processing secondary audio");

    /* Variables */
    int window_size;

    SNDFILE *sf; // Pointer to input.wav
    SF_INFO info; // Struct that stores info about input.wav
    int num_items,seekable,f,sr,c; // Stores info about input.wav; f = frames, sr = sample rate, c = channels
    double audio_duration;
    double *temp_buf; // Stores wav data read by libsnfile (stereo)
    double *sec_audio_sampledata_buffer; // Stores wav data read by libsnfile
    double *main_audio_sampledata_buffer; // Stores wav data read by libsnfile
    int main_duration;
    int sec_duration;

    /* Open the secondary WAV file with libsnfile sf_open */
    info.format = 0;
    sf = sf_open("SecondaryInput.wav",SFM_READ,&info);
    if (sf == NULL)
    {
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
    sec_duration = audio_duration*1000;

    /* Tells mainwindow to update the console with these outputs */
    emit processUpdate("Frames = " + QString::number(info.frames));
    emit processUpdate("SampleRate = " + QString::number(info.samplerate));
    emit processUpdate("Channels = " + QString::number(info.channels));
    emit processUpdate("NumItems = " + QString::number(num_items));
    emit processUpdate("Seekable = " + QString::number(info.seekable));
    emit processUpdate("Audio Length(seconds) = " + QString::number(audio_duration));

    /* Allocate space for the data to be read */
    window_size = num_items;
    temp_buf = (double *) malloc(num_items*sizeof(double));
    sec_audio_sampledata_buffer = (double *) malloc((window_size/2)*sizeof(double));


    /* Read data from wav file */
    sf_read_double(sf,temp_buf,num_items);

    /* Free memory */
    sf_close(sf);

    /* Average left and right channels */
    int temp_buf_index=0;
    for (int i = 0; i < num_items; i += 2)
    {
        double average = 0.0;
        for (int j = 0; j < 2; ++j)
        {
            average+=temp_buf[i+j];
        }
        average = average/2.0;
        sec_audio_sampledata_buffer[temp_buf_index]=average;
        temp_buf_index++;
    }

    free(temp_buf);
    emit processUpdate("Done processing secondary audio");
    emit processUpdate("Search starting");

    /* Open the main WAV file with libsnfile sf_open */
    info.format = 0;
    sf = sf_open("MainInput.wav",SFM_READ,&info);
    if (sf == NULL)
    {
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

    /* Read in size of segment */
    int search_size = window_size; // frames * channels
    int time_shift = sr;

    /* Allocate space to read main audio data */
    temp_buf = (double *) malloc(search_size*sizeof(double)); // allocate window size first
    main_audio_sampledata_buffer = (double *) malloc((window_size/2)*sizeof(double));

    /* First read in a segment the size of the secondary audio (window_size) */
    int num_read=0;
    int seg_num = 0;

    while (num_items-num_read>=search_size)
    {


        /* Check if its the first segment */
        if(seg_num==0)
        {
            /* Read audio data into temp_buf */
            int items_read=(sf_read_double(sf,temp_buf,search_size));
            num_read+=items_read;

            qDebug()<<"search size1: "<<search_size;
            qDebug()<<"items_read1: "<<items_read;
            qDebug()<<"num_read1: "<<num_read;


            /* Average out values */
            int index=0;
            double average = 0.0;
            for (int i = 0; i < items_read; i += 2)
            {
                average+=temp_buf[i];
                average+=temp_buf[i+1];
                average = average/2.0;
                main_audio_sampledata_buffer[index]=average;
                //out<<average<<" ";
                index++;
            }

            /* Perform cross correlation */
            alglib::real_1d_array sec_signal;
            sec_signal.setcontent(window_size/2,sec_audio_sampledata_buffer);

            alglib::real_1d_array main_signal;
            main_signal.setcontent(window_size/2,main_audio_sampledata_buffer);

            alglib::real_1d_array corrResult;
            corrResult.setlength((window_size)-2);
            alglib::corrr1d(main_signal, window_size/2, sec_signal, window_size/2, corrResult);

            /* Get max value of correlation results */
            double max=0.0;
            int maxCrossCorrelationIndex = 0;
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
            for (int i=0;i<window_size/2;i++) {
                mean_main += main_signal[i];
                mean_secondary += sec_signal[i];
            }
            mean_main/= search_size;
            mean_secondary /= search_size;

            /* Calculate the denominator */
            double sx = 0;
            double sy = 0;
            for (int i=0;i<window_size/2;i++) {
                sx += (main_signal[i] - mean_main) * (main_signal[i] - mean_main);
                sy += (sec_signal[i] - mean_secondary) * (sec_signal[i] - mean_secondary);
            }
            double denom = sqrt(sx*sy);

            /* Calcualte the coefficient */
            double coefficient = max/denom;

            /* If not part of segment & coefficient below criteria, carry on searching */
            /* If part of segment &  coefficient below criteria, end segment & save end timing as last searched time
                        * And update search table */
            qDebug()<<"coefficient: "<<coefficient;


            /* Free temp_buf */
            free(temp_buf);

            /* If there are stuffs left to search */
            if(num_items-search_size>0)
            {
                /* Change search size to 1/2 sec (samplerate/2) */
                if(num_items-search_size>time_shift)
                {
                    search_size=time_shift;
                }
                else
                {
                    search_size = num_items-search_size;
                }

                /* Reallocate size of temp_buf */
                temp_buf = (double *) malloc(search_size*sizeof(double));
            }
        }
        else
        {
            /* Shift main_audio_sampledata_buffer by time_shift towards the left */
            for(int i=0;i<((window_size/2)-(time_shift/2));i++)
            {
                main_audio_sampledata_buffer[i]=main_audio_sampledata_buffer[i+(time_shift/2)];
            }

            /* Read audio data into temp_buf */
            int items_read=(sf_read_double(sf,temp_buf,search_size));
            num_read+=items_read;


            qDebug()<<"search size2: "<<search_size;
            qDebug()<<"items_read2: "<<items_read;
            qDebug()<<"num_read2: "<<num_read;
            qDebug()<<"segment number"<<seg_num;


            /* Average out values in temp_buf */
            int index=0;
            double average = 0.0;
            double *temp_buf_frames = (double *) malloc(search_size/2*sizeof(double));

            for (int i = 0; i < items_read; i += 2)
            {
                average+=temp_buf[i];
                average+=temp_buf[i+1];
                average = average/2.0;
                temp_buf_frames[index]=average;
                //out<<average<<" ";
                index++;
            }

            /* Insert temp_buf_frames into main_audio_sampledata_buffer */
            temp_buf_index=0;
            for(int i=((window_size/2)-(time_shift/2));(i<window_size/2);i++)
            {
                main_audio_sampledata_buffer[i]=temp_buf_frames[temp_buf_index];
                temp_buf_index++;
            }

            free(temp_buf_frames);

            /* Perform cross correlation */

            alglib::real_1d_array sec_signal;
            sec_signal.setcontent(window_size/2,sec_audio_sampledata_buffer);

            alglib::real_1d_array main_signal;
            main_signal.setcontent(window_size/2,main_audio_sampledata_buffer);

            alglib::real_1d_array corrResult;
            corrResult.setlength((search_size*2)-2);
            alglib::corrr1d(main_signal, window_size/2, sec_signal, window_size/2, corrResult);

            /* Get max value of correlation results */
            double max=0.0;
            int maxCrossCorrelationIndex = 0;
            for(int i=0;i<corrResult.length();i++)
            {
                if(corrResult[i]> max)
                {
                    maxCrossCorrelationIndex=i;
                    max = corrResult[i];
                }
            }
            max=corrResult[0];
            /* Calculate the mean of the two series x[], y[] */
            double mean_main = 0;
            double mean_secondary = 0;
            for (int i=0;i<window_size/2;i++) {
                mean_main += main_signal[i];
                mean_secondary += sec_signal[i];
            }
            mean_main/= window_size/2;
            mean_secondary /= window_size/2;

            /* Calculate the denominator */
            double sx = 0;
            double sy = 0;
            for (int i=0;i<window_size/2;i++) {
                sx += (main_signal[i] - mean_main) * (main_signal[i] - mean_main);
                sy += (sec_signal[i] - mean_secondary) * (sec_signal[i] - mean_secondary);
            }
            double denom = sqrt(sx*sy);

            /* Calcualte the coefficient */
            double coefficient = max/denom;

            /* If not part of segment & coefficient below criteria, carry on searching */
            /* If part of segment &  coefficient below criteria, end segment & save end timing as last searched time
                                    * And update search table */
            qDebug()<<"coefficient: "<<coefficient;

        }
        seg_num++;

       /* if coefficient above threshold, use sec duration to get end */
    }

    free(temp_buf);
    free(main_audio_sampledata_buffer);
    free(sec_audio_sampledata_buffer);
}
