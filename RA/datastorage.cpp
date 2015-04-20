#include "datastorage.h"
#include <QString>
#include <QObject>
#include "fftw/fftw3.h"
#include <fstream>
#include <iostream>
#include "libsndfile/include/sndfile.hh"
#include <QEventLoop>
#include <QCoreApplication>
#include <vector>
#include <QDebug>

dataStorage::dataStorage()
{
    m_main_audio_buffer=NULL;
    m_secondary_audio_buffer=NULL;
}

void dataStorage::setMainBufferSize(int size)
{
    m_main_audio_buffer_size = size;
}

void dataStorage::setSecondaryBufferSize(int size)
{
    m_secondary_audio_buffer_size = size;
}

double* dataStorage::getMainBuffer()
{
    return m_main_audio_buffer;
}

double* dataStorage::getSecondaryBuffer()
{
    return m_secondary_audio_buffer;
}

void dataStorage::setMainBuffer(double *buffer)
{
    if(m_main_audio_buffer!=NULL)
    {
        qDebug()<<"freeing buffer";
        free(m_main_audio_buffer);
    }
    m_main_audio_buffer = buffer;
}

void dataStorage::setSecondaryBuffer(double *buffer)
{
    if(m_secondary_audio_buffer!=NULL)
    {
         qDebug()<<"freeing buffer";
        free(m_secondary_audio_buffer);
    }
    m_secondary_audio_buffer = buffer;
}

int dataStorage::getMainBufferSize()
{
    return m_main_audio_buffer_size;
}

int dataStorage::getSecondaryBufferSize()
{
    return m_secondary_audio_buffer_size;
}

void dataStorage::setMainNumFrame(int num_frames)
{
    m_main_num_frame=num_frames;
}

void dataStorage::setMainSampleRate(int sr)
{
    m_main_sr=sr;
}

int dataStorage::getMainNumFrame()
{
    return m_main_num_frame;
}

int dataStorage::getMainSampleRate()
{
    return m_main_sr;
}

void dataStorage::setAcceptedCrossCorrelationResults(std::vector <double> * results)
{
    m_accepted_cross_correlation_results = results;
}

std::vector <double> *dataStorage::getAcceptedCrossCorrelationResults()
{
    return m_accepted_cross_correlation_results;
}

void dataStorage::addTrimDetails(trimDetail *trimDetails)
{
    if(m_trimList.size()>0)
    {
        m_trimList.push_back(trimDetails);
        /* Sort in ascending order */
        int index = m_trimList.size()-1;
        trimDetail temp;
        int previous = m_trimList[index-1]->getStartTime();
        while(index!=0 && previous > trimDetails->getStartTime())
        {
            qDebug()<<"before swap "<< index;
            temp = *m_trimList[index-1];
            *m_trimList[index-1] = *m_trimList[index];
            *m_trimList[index]= temp;
            index--;
             qDebug()<<"after swap "<< index;
            if(index!=0)
            {
                previous = m_trimList[index-1]->getStartTime();
            }
        }
    }
    else
    {
        m_trimList.push_back(trimDetails);
    }
}

std::vector<trimDetail*> dataStorage::getTrimList()
{
    return m_trimList;
}

void dataStorage::addAudioSearchResult(trimDetail *trimDetails)
{
    if(m_audioSearchList.size()>0)
    {
        m_audioSearchList.push_back(trimDetails);
        /* Sort in ascending order */
        int index = m_audioSearchList.size()-1;
        trimDetail temp;
        int previous = m_audioSearchList[index-1]->getStartTime();
        while(index!=0 && previous > trimDetails->getStartTime())
        {
            qDebug()<<"before swap "<< index;
            temp = *m_audioSearchList[index-1];
            *m_audioSearchList[index-1] = *m_audioSearchList[index];
            *m_audioSearchList[index]= temp;
            index--;
             qDebug()<<"after swap "<< index;
            if(index!=0)
            {
                previous = m_audioSearchList[index-1]->getStartTime();
            }
        }
    }
    else
    {
        m_audioSearchList.push_back(trimDetails);
    }
}

std::vector<trimDetail*> dataStorage::getAudioSearchList()
{
    return m_audioSearchList;
}

void dataStorage::setMainVideoDuration(int duration)
{
    m_main_video_duration = duration;
}

int dataStorage::getMainVideoDuration()
{
    return m_main_video_duration;
}

void dataStorage::deleteTrimDetails(int index)
{
    m_trimList.erase(m_trimList.begin() + index);

}

void dataStorage::addJoinDetails(trimDetail *trimDetails)
{
    if(m_joinList.size()>0)
    {
       m_joinList.push_back(trimDetails);
        /* Sort in ascending order */
        int index = m_joinList.size()-1;
        trimDetail temp;
        int previous = m_joinList[index-1]->getStartTime();
        while(index!=0 && previous > trimDetails->getStartTime())
        {
            qDebug()<<"before swap "<< index;
            temp = *m_joinList[index-1];
            *m_joinList[index-1] = *m_joinList[index];
            *m_joinList[index]= temp;
            index--;
             qDebug()<<"after swap "<< index;
            if(index!=0)
            {
                previous = m_joinList[index-1]->getStartTime();
            }
        }
    }
    else
    {
        m_joinList.push_back(trimDetails);
    }
}

void dataStorage::deleteJoinDetails(int index)
{
    m_joinList.erase(m_joinList.begin() + index);
}

 std::vector<trimDetail*> dataStorage::getJoinList()
 {
     return m_joinList;
 }

 void dataStorage::increaseTrimTime(int duration, int after_this_timestamp)
 {
    for(int i=0;i<m_trimList.size();i++)
    {
        if(m_trimList[i]->getStartTime()>after_this_timestamp)
        {
            int new_start_time = m_trimList[i]->getStartTime() + duration;
            int new_end_time = m_trimList[i]->getEndTime() + duration;
            int new_start_hr = new_start_time/(1000*60*60);
            int new_start_min = (new_start_time/(1000*60))%60;
            int new_start_sec = (new_start_time/(1000))%60;
            int new_start_milisec = new_start_time % 1000;
            int new_end_hr = new_end_time/(1000*60*60);
            int new_end_min = (new_end_time/(1000*60))%60;
            int new_end_sec = (new_end_time/(1000))%60;
            int new_end_milisec = new_end_time % 1000;

            QString new_start_time_text = QString::number(new_start_hr)+":"+QString::number(new_start_min)+":"+QString::number(new_start_sec)+"."+QString::number(new_start_milisec);
            QString new_end_time_text = QString::number(new_end_hr)+":"+QString::number(new_end_min)+":"+QString::number(new_end_sec)+"."+QString::number(new_end_milisec);
            qDebug()<<"new start time: "<<new_start_time_text;
            qDebug()<<"new end time: "<<new_end_time_text;
            m_trimList[i]->setStartTime(new_start_time);
            m_trimList[i]->setEndTime(new_end_time);
            m_trimList[i]->setStartTimeText(new_start_time_text);
            m_trimList[i]->setEndTimeText(new_end_time_text);
        }
    }
 }

 void dataStorage::increaseJoinTime(int duration, int after_this_timestamp)
 {
     for(int i=0;i<m_joinList.size();i++)
     {
         if(m_joinList[i]->getStartTime()>after_this_timestamp)
         {
             int new_start_time = m_joinList[i]->getStartTime() + duration;
             int new_end_time = m_joinList[i]->getEndTime() + duration;
             int new_start_hr = new_start_time/(1000*60*60);
             int new_start_min = (new_start_time/(1000*60))%60;
             int new_start_sec = (new_start_time/(1000))%60;
             int new_start_milisec = new_start_time % 1000;
             int new_end_hr = new_end_time/(1000*60*60);
             int new_end_min = (new_end_time/(1000*60))%60;
             int new_end_sec = (new_end_time/(1000))%60;
             int new_end_milisec = new_end_time % 1000;

             QString new_start_time_text = QString::number(new_start_hr)+":"+QString::number(new_start_min)+":"+QString::number(new_start_sec)+"."+QString::number(new_start_milisec);
             QString new_end_time_text = QString::number(new_end_hr)+":"+QString::number(new_end_min)+":"+QString::number(new_end_sec)+"."+QString::number(new_end_milisec);

             m_joinList[i]->setStartTime(new_start_time);
             m_joinList[i]->setEndTime(new_end_time);
             m_joinList[i]->setStartTimeText(new_start_time_text);
             m_joinList[i]->setEndTimeText(new_end_time_text);
         }
     }
 }

 void dataStorage::increaseMuteTime(int duration, int after_this_timestamp)
 {
     for(int i=0;i<m_audioSearchList.size();i++)
     {
         if(m_joinList[i]->getStartTime()>after_this_timestamp)
         {
             int new_start_time = m_audioSearchList[i]->getStartTime() + duration;
             int new_end_time = m_audioSearchList[i]->getEndTime() + duration;
             int new_start_hr = new_start_time/(1000*60*60);
             int new_start_min = (new_start_time/(1000*60))%60;
             int new_start_sec = (new_start_time/(1000))%60;
             int new_start_milisec = new_start_time % 1000;
             int new_end_hr = new_end_time/(1000*60*60);
             int new_end_min = (new_end_time/(1000*60))%60;
             int new_end_sec = (new_end_time/(1000))%60;
             int new_end_milisec = new_end_time % 1000;

             QString new_start_time_text = QString::number(new_start_hr)+":"+QString::number(new_start_min)+":"+QString::number(new_start_sec)+"."+QString::number(new_start_milisec);
             QString new_end_time_text = QString::number(new_end_hr)+":"+QString::number(new_end_min)+":"+QString::number(new_end_sec)+"."+QString::number(new_end_milisec);

             m_audioSearchList[i]->setStartTime(new_start_time);
             m_audioSearchList[i]->setEndTime(new_end_time);
             m_audioSearchList[i]->setStartTimeText(new_start_time_text);
             m_audioSearchList[i]->setEndTimeText(new_end_time_text);
         }
     }
 }

 void dataStorage::deleteMuteDetails(int index)
 {
     m_audioMuteList.erase(m_audioMuteList.begin() + index);
 }

 std::vector<trimDetail*> dataStorage::getMuteList()
 {
    return m_audioMuteList;
 }

 void dataStorage::addMuteDetails(trimDetail *trimDetails)
 {
     if(m_audioMuteList.size()>0)
     {
        m_audioMuteList.push_back(trimDetails);
         /* Sort in ascending order */
         int index = m_audioMuteList.size()-1;
         trimDetail temp;
         int previous = m_audioMuteList[index-1]->getStartTime();
         while(index!=0 && previous > trimDetails->getStartTime())
         {
             qDebug()<<"before swap "<< index;
             temp = *m_audioMuteList[index-1];
             *m_audioMuteList[index-1] = *m_audioMuteList[index];
             *m_audioMuteList[index]= temp;
             index--;
              qDebug()<<"after swap "<< index;
             if(index!=0)
             {
                 previous = m_audioMuteList[index-1]->getStartTime();
             }
         }
     }
     else
     {
         m_audioMuteList.push_back(trimDetails);
     }
 }
