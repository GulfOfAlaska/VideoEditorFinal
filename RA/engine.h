#ifndef ENGINE_H
#define ENGINE_H

#include <QString>
#include <QObject>
#include "fftw/fftw3.h"
#include <fstream>
#include <iostream>
#include "libsndfile/include/sndfile.hh"
#include "mainwindow.h"
#include "datastorage.h"
#include <QEventLoop>
#include <QCoreApplication>

class Engine: public QObject
{
    Q_OBJECT

public:
    // Constructors
    Engine();
    Engine(QString filepath, int mainOrSecondary, dataStorage* storage){
        m_filepath = filepath;
        m_mainOrSecondary = mainOrSecondary;
        m_datastorage = storage;
        PI = 3.142;
    }
    void insertVideo(QString start_time_text,int start_time,int clip_duration, QString clip_filepath);
    void undoInsertVideo(int join_list_index);

public slots:
    // Functions
    int GetData();
    void DrawSpectogramFinished();
    void SearchAudio();
    void exportVideo();
    void exportTrims();
    void exportMutes();


signals:
    void processUpdate(QString text);
    void mainSpgmUpdate(fftw_complex *fftout, int num_items);
    void secondarySpgmUpdate(fftw_complex *fftout, int num_items);
    void mainSWUpdate(double *buf, int num_items);
    void corrUpdate(double *buf, int num_items);
    void updateAudioSearchTable();
    void started();
    void finished();
    void readFinished();


private:
    // Members
    QString m_filepath; // Stores filepath of video/audio 
    fftw_complex *fftout;
    fftw_complex *fftout_secondary;
    fftw_plan p_secondary;
    fftw_plan p_main;
    fftw_plan p_reverse;
    int m_mainOrSecondary;
    dataStorage* m_datastorage;
    double PI;

    // Functions
    int ConvertToWav(QString filepath); // Convert media file to wav format
    QString GetRandomString(int length); // Generate random char for converted wav filename
    void cutVideo(QString start_time, QString end_time, QString output_file);
    void concatenateVideo(QString start_video, QString end_video, QString output_file); 
    void muteVideo(QString input_file, QString output_file);
    int numDigits(int num);
};

#endif // ENGINE_H
