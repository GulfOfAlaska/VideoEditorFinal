#ifndef DATASTORAGE_H
#define DATASTORAGE_H

#include <QString>
#include <QObject>
#include "fftw/fftw3.h"
#include <fstream>
#include <iostream>
#include "libsndfile/include/sndfile.hh"
#include <QEventLoop>
#include <vector>
#include <QCoreApplication>
#include "trimdetail.h"

class dataStorage
{
public:
    dataStorage();

    /* Sample data storage functions */
    double *getMainBuffer();
    double *getSecondaryBuffer();
    void setMainBuffer(double *buffer);
    void setSecondaryBuffer(double *buffer);
    void setMainBufferSize(int size);
    void setSecondaryBufferSize(int size);
    int getMainBufferSize();
    int getSecondaryBufferSize();
    void setMainNumFrame(int num_frames);
    void setMainSampleRate(int sr);
    int getMainNumFrame();
    int getMainSampleRate();
    void setAcceptedCrossCorrelationResults(std::vector <double> * results);
    void addTrimDetails(trimDetail *trimDetails);
    void deleteTrimDetails(int index);
    std::vector<trimDetail*> getTrimList();
    void addAudioSearchResult(trimDetail *trimDetails);
    std::vector<trimDetail*> getAudioSearchList();
    void setMainVideoDuration(int duration);
    int getMainVideoDuration();
    void addJoinDetails(trimDetail *trimDetails);
    void deleteJoinDetails(int index);
    std::vector<trimDetail*> getJoinList();
    void increaseTrimTime(int duration, int after_this_timestamp);
    void increaseJoinTime(int duration, int after_this_timestamp);
    void increaseMuteTime(int duration, int after_this_timestamp);
    void deleteMuteDetails(int index);
    std::vector<trimDetail*> getMuteList();
    void addMuteDetails(trimDetail *trimDetails);
    void clearSearchDetails();

private:
    double *m_main_audio_buffer;
    double *m_secondary_audio_buffer;
    int m_main_audio_buffer_size;
    int m_secondary_audio_buffer_size;
    int m_main_num_frame;
    int m_main_sr;
    std::vector <double> *m_accepted_cross_correlation_results;
    std::vector <double> *getAcceptedCrossCorrelationResults();
    std::vector <trimDetail*> m_trimList;
    std::vector <trimDetail*> m_audioSearchList;
    std::vector <trimDetail*> m_joinList;
    std::vector <trimDetail*> m_audioMuteList;
    int m_main_video_duration;
};

#endif // DATASTORAGE_H
