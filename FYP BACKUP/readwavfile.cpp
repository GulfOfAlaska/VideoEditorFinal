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