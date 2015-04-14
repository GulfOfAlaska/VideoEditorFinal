#ifndef TRIMDETAIL_H
#define TRIMDETAIL_H

#include <QString>
class trimDetail
{
public:
    trimDetail();
    void setStartTime(int position);
    void setEndTime(int position);
    void setName(QString name);
    void setStartTimeText(QString start_time_text);
    void setEndTimeText(QString end_time_text);
    void setDuration(int duration);
    int getStartTime();
    int getEndTime();
    int getDuration();
    QString getName();
    QString getStartTimeText();
    QString getEndTimeText();



private:
    int m_start_time;
    int m_end_time;
    int m_duration;
    QString m_name;
    QString m_start_time_text;
    QString m_end_time_text;
};

#endif // TRIMDETAIL_H
