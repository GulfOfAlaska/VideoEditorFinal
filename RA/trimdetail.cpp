#include "trimdetail.h"

trimDetail::trimDetail()
{
}

void trimDetail::setStartTime(int position)
{
    m_start_time = position;
}
void trimDetail::setEndTime(int position)
{
    m_end_time = position;
}

void trimDetail::setName(QString  name)
{
    m_name = name;
}

int trimDetail::getStartTime()
{
    return m_start_time;
}

int trimDetail::getEndTime()
{
    return m_end_time;
}

QString trimDetail::getName()
{
    return m_name;
}

void trimDetail::setStartTimeText(QString start_time_text)
{
    m_start_time_text=start_time_text;
}

void trimDetail::setEndTimeText(QString end_time_text)
{
    m_end_time_text=end_time_text;
}

QString trimDetail::getStartTimeText()
{
    return m_start_time_text;
}
QString trimDetail::getEndTimeText()
{
    return m_end_time_text;
}

void trimDetail::setDuration(int duration)
{
    m_duration = duration;
}

int trimDetail::getDuration()
{
    return m_duration;
}
