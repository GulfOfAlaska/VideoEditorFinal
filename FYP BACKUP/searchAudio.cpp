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