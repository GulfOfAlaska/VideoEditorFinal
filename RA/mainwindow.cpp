#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "engine.h"
#include <QFileDialog>
#include <QThread>
#include <QPointF>
#include <QPainter>
#include <QPixmap>
#include <QVideoWidget>
#include <QMediaObject>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "trimdetail.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_datastorage = new dataStorage();
    vplayer = new QMediaPlayer;
    aplayer = new QMediaPlayer;
    joinPreviewVplayer = new QMediaPlayer;
    m_insert_number=0;
    m_undo_insert_number=0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initMainVideo()
{
    qDebug()<<"initing video";
    /* Initialise video player */
    vplayer->setVideoOutput(ui->videoScreen);
    vplayer->setMedia(QUrl(m_main_filepath));
    QObject::connect(vplayer,SIGNAL(durationChanged(qint64)),this,SLOT(updateVideoDuration(qint64)));

    /* Initialise seeker range */
    qDebug()<<"duration: "<<vplayer->duration();
    ui->seekBar->setRange(0,vplayer->duration());
    ui->videoProgressBar->setValue(100);
}

void MainWindow::updateVideoUiLabel(QImage* frame)
{
    //    qDebug()<<"updating label";
    //    ui->videoScreenLabel->setPixmap(QPixmap::fromImage(*frame));
}

void MainWindow::updateUiLabel(QString text)
{

    QString temp = ui->processUpdateLabel->text();
    temp.append("\n"+text);
    ui->processUpdateLabel->setText( temp );
}

void MainWindow::on_actionOpen_triggered()
{
    ui->videoProgressBar->setMaximum(100);
     ui->videoProgressBar->setValue(0);
    /* Let user determine filepath */
    QString selfilter = tr("All files (*.*)");
    m_main_filepath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif)" ),
                &selfilter);

    if (m_main_filepath != "")
    {

        /* Create an engine thread */
        Engine*Eng =  new Engine(m_main_filepath,1,m_datastorage);
        QThread * get_audio_data_th = new QThread();
        QObject::connect(get_audio_data_th,SIGNAL(started()),Eng,SLOT(GetData()));
        QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
        QObject::connect(Eng, SIGNAL(readFinished()),this, SLOT(initMainVideo()));
        Eng->moveToThread(get_audio_data_th);
        get_audio_data_th->start();
    }
    return;
}

void MainWindow::on_chooseAudio_clicked()
{
    QString selfilter = tr("All files (*.*)");
    m_secondary_filepath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif)" ),
                &selfilter);

    if (m_secondary_filepath != "")
    {
        // Create a thread to get data from media file
        Engine*Eng =  new Engine(m_secondary_filepath,2,m_datastorage);
        QThread * get_secondary_audio_data_th = new QThread();
        QObject::connect(get_secondary_audio_data_th,SIGNAL(started()),Eng,SLOT(GetData()));
        QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
        Eng->moveToThread(get_secondary_audio_data_th);
        get_secondary_audio_data_th->start();
    }
    return;
}

void MainWindow::on_searchAudio_clicked()
{
    /* Clear search results if any */
    std::vector<trimDetail*> detail_list = m_datastorage->getAudioSearchList();

    for(int i=0; i<detail_list.size(); i++)
    {
        m_datastorage->clearSearchDetails();
    }

    ui->audioProgressBar->setValue(0);
    int main_duration = m_datastorage->getMainVideoDuration()/1000;
    setAudioProgressBarMaxValue(main_duration*2);
    // Create a thread to get data from media file
    Engine*Eng =  new Engine(m_secondary_filepath,2,m_datastorage);
    QThread * cross_correlation_th = new QThread();
    QObject::connect(cross_correlation_th,SIGNAL(started()),Eng,SLOT(SearchAudio()));
    QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
    QObject::connect(Eng, SIGNAL(updateAudioSearchTable()),this, SLOT(updateAudioSearchList()));
    QObject::connect(Eng, SIGNAL(updateAudioSamplesSearched(int)),this,SLOT(updateAudioProgressBarValue(int)));
    Eng->moveToThread(cross_correlation_th);
    cross_correlation_th->start();
}

void MainWindow::on_seekBar_sliderMoved(int position)
{
    int newPosition=position;
    if(m_main_filepath!="")
    {
        /* Check if slider in within any trim timing */
        std::vector <trimDetail*> trim_list = m_datastorage->getTrimList();
        for(int i=0; i<trim_list.size();i++)
        {
            int start = trim_list[i]->getStartTime();
            int end = trim_list[i]->getEndTime();
            if(position>=start && position<end)
            {
                newPosition = end;
            }
        }
        vplayer->setPosition(newPosition);
    }
}

void MainWindow::updateSeekBar(qint64 position)
{
    ui->seekBar->setSliderPosition(position);
    int slider_position = ui->seekBar->sliderPosition();
    int hr = slider_position/(1000*60*60);
    int min = (slider_position/(1000*60))%60;
    int sec = (slider_position/(1000))%60;
    int milisec = slider_position % 1000;
    ui->seekBarTime->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));
}

void MainWindow::updateVideoDuration(qint64 duration)
{
    ui->seekBar->setMaximum(duration);
    m_datastorage->setMainVideoDuration(duration);
}

void MainWindow::on_getTrimStart_clicked()
{
    int start_position = ui->seekBar->sliderPosition();
    int hr = start_position/(1000*60*60);
    int min = (start_position/(1000*60))%60;
    int sec = (start_position/(1000))%60;
    int milisec = start_position % 1000;
    ui->trimStart->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));

}

void MainWindow::on_getTrimEnd_clicked()
{
    int end_position = ui->seekBar->sliderPosition();
    int hr = end_position/(1000*60*60);
    int min = (end_position/(1000*60))%60;
    int sec = (end_position/(1000))%60;
    int milisec = end_position % 1000;
    ui->trimEnd->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));
}

void MainWindow::on_cutVideo_clicked()
{
    QString name = ui->trimName->text();
    QString start_time = ui->trimStart->text();
    int start_hr = start_time.split(":")[0].toInt();
    int start_min = start_time.split(":")[1].toInt();
    int start_sec = start_time.split(":")[2].toInt();
    int start_milisec = start_time.split(":")[3].toInt();
    int start_duration_millisec = start_hr*(1000*60*60) + start_min*(1000*60) + start_sec*(1000)+ start_milisec;
    qDebug()<<start_duration_millisec;

    QString end_time = ui->trimEnd->text();
    int end_hr = end_time.split(":")[0].toInt();
    int end_min = end_time.split(":")[1].toInt();
    int end_sec = end_time.split(":")[2].toInt();
    int end_milisec = end_time.split(":")[3].toInt();
    int end_duration_millisec = end_hr*(1000*60*60) + end_min*(1000*60) + end_sec*(1000)+ end_milisec;
    qDebug()<<end_duration_millisec;

    if(end_duration_millisec > start_duration_millisec)
    {
        trimDetail *trim_detail = new trimDetail;
        trim_detail->setName(name);
        trim_detail->setStartTime(start_duration_millisec);
        trim_detail->setEndTime(end_duration_millisec);
        trim_detail->setStartTimeText(QString::number(start_hr)+":"+QString::number(start_min)+":"+QString::number(start_sec)+"."+QString::number(start_milisec));
        trim_detail->setEndTimeText(QString::number(end_hr)+":"+QString::number(end_min)+":"+QString::number(end_sec)+"."+QString::number(end_milisec));
        m_datastorage->addTrimDetails(trim_detail);

        updateTrimListTable();
    }
}

void MainWindow::updateTrimListTable()
{
    trimDetail* details;
    QString name;
    QString startTime;
    QString endTime;

    std::vector<trimDetail*> detail_list = m_datastorage->getTrimList();
    ui->trimListTable->setRowCount(detail_list.size());
    ui->trimListTable->setColumnCount(3);
    for(int i=0; i<detail_list.size(); i++)
    {
        details = detail_list[i];
        name = details->getName();
        startTime = details->getStartTimeText();
        endTime = details->getEndTimeText();

        ui->trimListTable->setItem(i,2,new QTableWidgetItem(name));
        ui->trimListTable->setItem(i,0,new QTableWidgetItem(startTime));
        ui->trimListTable->setItem(i,1,new QTableWidgetItem(endTime));
        ui->trimListTable->horizontalHeader()->setStretchLastSection(true);
    }
}

void MainWindow::updateJoinListTable()
{
    trimDetail* details;
    QString name;
    QString startTime;
    QString endTime;

    std::vector<trimDetail*> detail_list = m_datastorage->getJoinList();
    ui->joinListTable->setRowCount(detail_list.size());
    ui->joinListTable->setColumnCount(3);
    for(int i=0; i<detail_list.size(); i++)
    {
        details = detail_list[i];
        name = details->getName();
        startTime = details->getStartTimeText();
        endTime = details->getEndTimeText();

        ui->joinListTable->setItem(i,2,new QTableWidgetItem(name));
        ui->joinListTable->setItem(i,0,new QTableWidgetItem(startTime));
        ui->joinListTable->setItem(i,1,new QTableWidgetItem(endTime));
        ui->joinListTable->horizontalHeader()->setStretchLastSection(true);
    }
}

void MainWindow::skipTrimmedParts(qint64 position)
{

    int newPosition = position;
    std::vector <trimDetail*> trim_list = m_datastorage->getTrimList();
    for(int i=0; i<trim_list.size();i++)
    {
        int start = trim_list[i]->getStartTime();
        int end = trim_list[i]->getEndTime();
        if(position>=start && position<end)
        {
            newPosition = end;
            vplayer->setPosition(newPosition);
        }
    }
}

void MainWindow::muteSearchedParts(qint64 position)
{
    std::vector <trimDetail*> mute_list = m_datastorage->getMuteList();
    bool mute=false;
    for(int i=0; i<mute_list.size();i++)
    {
        int start = mute_list[i]->getStartTime();
        int end = mute_list[i]->getEndTime();
        if(position>=start && position<end)
        {
            qDebug()<<"true";
            vplayer->setMuted(true);
            mute=true;
        }
    }
    if(mute==false)
    {
       vplayer->setMuted(false);
    }
}


void MainWindow::on_playVideo_clicked()
{
    //    AudioPlayer = new player;
    //    QThread * playThread = new QThread();
    //   // QObject::connect(playThread,SIGNAL(started()),AudioPlayer,SLOT(playAudio()));
    //    QObject::connect(playThread,SIGNAL(started()),AudioPlayer,SLOT(playVideo()));
    //    QObject::connect(AudioPlayer, SIGNAL(updateVideoLabel(frame)),this, SLOT(updateUiVideoLabel(frame)),Qt::DirectConnection);
    //    AudioPlayer->moveToThread(playThread);
    //    playThread->start();
    /* Initialise video player */

    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(updateSeekBar(qint64)));
    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(skipTrimmedParts(qint64)));
    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(muteSearchedParts(qint64)));
    QObject::disconnect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(previewStop(qint64)));


    int position = ui->seekBar->sliderPosition();
    vplayer->setPosition(position);
    if(m_main_filepath!="" && vplayer->state()==0) // Stopped state
    {
        vplayer->play();

    }
    if(m_main_filepath!="" && vplayer->state()==1) // Playing state
    {
        /* Do nothing */
    }
    if(m_main_filepath!="" && vplayer->state()==2) // Paused state
    {
        vplayer->play();
    }
}

void MainWindow::on_stopVideo_clicked()
{
    if(m_main_filepath!="" && vplayer->state()==1) // Playing state
    {
        vplayer->stop();
    }
}

void MainWindow::on_pauseVideo_clicked()
{
    if(m_main_filepath!="" && vplayer->state()==1) // Playing state
    {
        vplayer->pause();
    }
}

void MainWindow::updateAudioSearchList()
{
    qDebug()<<"updating";
    trimDetail* details;
    QString startTime;
    QString endTime;

    std::vector<trimDetail*> detail_list = m_datastorage->getAudioSearchList();
    ui->audioSearchTable->setRowCount(detail_list.size());
    ui->audioSearchTable->setColumnCount(2);
    for(int i=0; i<detail_list.size(); i++)
    {
        details = detail_list[i];
        startTime = details->getStartTimeText();
        endTime = details->getEndTimeText();

        ui->audioSearchTable->setItem(i,0,new QTableWidgetItem(startTime));
        ui->audioSearchTable->setItem(i,1,new QTableWidgetItem(endTime));
        ui->audioSearchTable->horizontalHeader()->setStretchLastSection(true);
    }
}

void MainWindow::on_audioSearchTable_cellClicked(int row, int column)
{
    m_selected_search_detail_index = row;

    std::vector <trimDetail*> search_list = m_datastorage->getAudioSearchList();
    m_selected_search_detail_start = search_list[m_selected_search_detail_index]->getStartTime();
    m_selected_search_detail_end = search_list[m_selected_search_detail_index]->getEndTime();
    QString start_time_text = search_list[m_selected_search_detail_index]->getStartTimeText();
    QString end_time_text = search_list[m_selected_search_detail_index]->getEndTimeText();
    start_time_text.replace(QString("."), QString(":"));
    end_time_text.replace(QString("."), QString(":"));
    ui->searchStartText->setText(start_time_text);
    ui->searchEndText->setText(end_time_text);
    ui->seekBar->setSliderPosition(m_selected_search_detail_start);
}

void MainWindow::on_actionExport_triggered()
{
    ui->videoProgressBar->setMaximum(100);
     ui->videoProgressBar->setValue(0);

    if (m_main_filepath != "")
    {
        Engine* Eng =  new Engine(m_main_filepath,1,m_datastorage);
        QThread * export_th = new QThread();
        QObject::connect(export_th,SIGNAL(started()),Eng,SLOT(exportVideo()));
        Eng->moveToThread(export_th);
        export_th->start();
    }
    return;
}

void MainWindow::on_trimListTable_cellClicked(int row, int column)
{
    m_selected_trim_detail_index = row;
}

void MainWindow::on_deleteTrim_clicked()
{
    m_datastorage->deleteTrimDetails(m_selected_trim_detail_index);
    updateTrimListTable();
}

void MainWindow::on_chooseVideoFromFile_clicked()
{
    QString selfilter = tr("All files (*.*)");
    m_join_video_filepath = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C://",
                tr("All files (*.*);;JPEG (*.jpg *.jpeg);;TIFF (*.tif)" ),
                &selfilter);

    if (m_join_video_filepath != "")
    {
        /* Initialise video player */
        joinPreviewVplayer->setVideoOutput(ui->JoinPreviewVideoScreen);
        joinPreviewVplayer->setMedia(QUrl(m_join_video_filepath));
    }
    return;
}

void MainWindow::on_JoinPreviewVPlay_clicked()
{
    if (m_join_video_filepath != "")
    {
        joinPreviewVplayer->play();
    }
}

void MainWindow::on_JoinPreviewVStop_clicked()
{
    if (m_join_video_filepath != "")
    {
        joinPreviewVplayer->stop();
    }
}

void MainWindow::on_JoinPreviewVPause_clicked()
{
    if (m_join_video_filepath != "")
    {
        joinPreviewVplayer->pause();
    }
}

void MainWindow::on_getInsertTime_clicked()
{
    int start_position = ui->seekBar->sliderPosition();
    int hr = start_position/(1000*60*60);
    int min = (start_position/(1000*60))%60;
    int sec = (start_position/(1000))%60;
    int milisec = start_position % 1000;
    ui->insertText->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));
}

void MainWindow::on_insertVideo_clicked()
{
    if(m_join_video_filepath!="" && ui->insertText->text()!="" )
    {
        ui->videoProgressBar->setMaximum(100);
        ui->videoProgressBar->setValue(0);

        QString name = ui->insertNote->text();
        QString start_time = ui->insertText->text();
        int start_hr = start_time.split(":")[0].toInt();
        int start_min = start_time.split(":")[1].toInt();
        int start_sec = start_time.split(":")[2].toInt();
        int start_milisec = start_time.split(":")[3].toInt();
        int start_duration_millisec = start_hr*(1000*60*60) + start_min*(1000*60) + start_sec*(1000)+ start_milisec;
        QString start_time_text = QString::number(start_hr)+":"+QString::number(start_min)+":"+QString::number(start_sec)+"."+QString::number(start_milisec);
        ui->videoProgressBar->setValue(20);

        int end_duration_millisec = start_duration_millisec + joinPreviewVplayer->duration();
        int end_hr = end_duration_millisec /(1000*60*60);
        int end_min = (end_duration_millisec /(1000*60))%60;
        int end_sec = (end_duration_millisec /(1000))%60;
        int end_milisec = end_duration_millisec  % 1000;
        QString end_time_text = QString::number(end_hr)+":"+QString::number(end_min)+":"+QString::number(end_sec)+"."+QString::number(end_milisec);

        ui->videoProgressBar->setValue(40);

        trimDetail *trim_detail = new trimDetail;
        trim_detail->setName(name);
        trim_detail->setStartTime(start_duration_millisec);
        trim_detail->setEndTime(end_duration_millisec);
        trim_detail->setStartTimeText(start_time_text);
        trim_detail->setEndTimeText(end_time_text);
        trim_detail->setDuration(joinPreviewVplayer->duration());
        m_datastorage->addJoinDetails(trim_detail);

        ui->videoProgressBar->setValue(60);

        Engine*Eng =  new Engine(m_main_filepath,m_datastorage,m_insert_number, start_time_text,start_duration_millisec,joinPreviewVplayer->duration(),m_join_video_filepath);
        QThread * insert_vid_th = new QThread();
        QObject::connect(insert_vid_th,SIGNAL(started()),Eng,SLOT(insertVideo()));
        QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
        QObject::connect(Eng, SIGNAL(insertFinished()),this, SLOT(initInsertVideo()));
        QObject::connect(Eng, SIGNAL(updateVideoProgressBar(int)),this,SLOT(updateVideoProgressBarValue(int)));
        Eng->moveToThread(insert_vid_th);
        insert_vid_th->start();
    }
}

void MainWindow::initInsertVideo()
{
    updateJoinListTable();
    updateTrimListTable();
    updateAudioSearchList();
    updateMuteListTable();

    qDebug()<<"switching main";
    m_main_filepath = QString::number(m_insert_number)+"joinResult.mp4";

    /* Create an engine thread */
    Engine*Eng =  new Engine(m_main_filepath,1,m_datastorage);
    QThread * get_audio_data_th = new QThread();
    QObject::connect(get_audio_data_th,SIGNAL(started()),Eng,SLOT(GetData()));
    QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
    QObject::connect(Eng, SIGNAL(readFinished()),this, SLOT(initMainVideo()));
    Eng->moveToThread(get_audio_data_th);
    get_audio_data_th->start();
    m_insert_number++;
}

void MainWindow::on_joinListTable_cellClicked(int row, int column)
{
    m_selected_join_detail_index=row;
}

void MainWindow::on_insertVideoUndo_clicked()
{
    if(m_datastorage->getJoinList().size()!=0)
    {
        Engine *Eng =  new Engine(m_main_filepath,1,m_datastorage,m_undo_insert_number);
        QThread * undo_insert_th = new QThread();
        QObject::connect(undo_insert_th,SIGNAL(started()),Eng,SLOT(undoInsertVideo()));
        QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
        QObject::connect(Eng, SIGNAL(readFinished()),this, SLOT(initMainVideo()));
        QObject::connect(Eng, SIGNAL(undoInsertFinished()),this, SLOT(initUndoInsertVideo()));
        Eng->moveToThread(undo_insert_th);
        undo_insert_th->start();
    }
}

void MainWindow::initUndoInsertVideo()
{
    updateJoinListTable();
    updateTrimListTable();
    updateAudioSearchList();
    updateMuteListTable();

    m_main_filepath = QString::number(m_undo_insert_number)+"undonejoinResult.mp4";
    Engine *Eng =  new Engine(m_main_filepath,1,m_datastorage);
    QThread * get_audio_data_th = new QThread();
    QObject::connect(get_audio_data_th,SIGNAL(started()),Eng,SLOT(GetData()));
    QObject::connect(Eng, SIGNAL(processUpdate(QString)),this, SLOT(updateUiLabel(QString)),Qt::DirectConnection);
    QObject::connect(Eng, SIGNAL(readFinished()),this, SLOT(initMainVideo()));
    Eng->moveToThread(get_audio_data_th);
    get_audio_data_th->start();
    m_undo_insert_number++;
}

void MainWindow::on_muteAudioPart_clicked()
{

    QString start_time = ui->searchStartText->text();
    int start_hr = start_time.split(":")[0].toInt();
    int start_min = start_time.split(":")[1].toInt();
    int start_sec = start_time.split(":")[2].toInt();
    int start_milisec = start_time.split(":")[3].toInt();
    int start_duration_millisec = start_hr*(1000*60*60) + start_min*(1000*60) + start_sec*(1000)+ start_milisec;

    QString end_time = ui->searchEndText->text();
    int end_hr = end_time.split(":")[0].toInt();
    int end_min = end_time.split(":")[1].toInt();
    int end_sec = end_time.split(":")[2].toInt();
    int end_milisec = end_time.split(":")[3].toInt();
    int end_duration_millisec = end_hr*(1000*60*60) + end_min*(1000*60) + end_sec*(1000)+ end_milisec;

    if(start_duration_millisec < end_duration_millisec)
    {
        trimDetail *trim_detail = new trimDetail;
        trim_detail->setStartTime(start_duration_millisec);
        trim_detail->setEndTime(end_duration_millisec);
        trim_detail->setStartTimeText(QString::number(start_hr)+":"+QString::number(start_min)+":"+QString::number(start_sec)+"."+QString::number(start_milisec));
        trim_detail->setEndTimeText(QString::number(end_hr)+":"+QString::number(end_min)+":"+QString::number(end_sec)+"."+QString::number(end_milisec));
        m_datastorage->addMuteDetails(trim_detail);
        updateMuteListTable();
    }


}

void MainWindow::updateMuteListTable()
{
    trimDetail* details;
    QString startTime;
    QString endTime;

    std::vector<trimDetail*> detail_list = m_datastorage->getMuteList();
    ui->muteListTable->setRowCount(detail_list.size());
    ui->muteListTable->setColumnCount(2);
    for(int i=0; i<detail_list.size(); i++)
    {
        details = detail_list[i];
        startTime = details->getStartTimeText();
        endTime = details->getEndTimeText();

        ui->muteListTable->setItem(i,0,new QTableWidgetItem(startTime));
        ui->muteListTable->setItem(i,1,new QTableWidgetItem(endTime));
        ui->muteListTable->horizontalHeader()->setStretchLastSection(true);
    }
}

void MainWindow::on_muteListTable_cellClicked(int row, int column)
{
    m_selected_mute_detail_index = row;
}

void MainWindow::on_pushButton_2_clicked()
{
    QString start_time = ui->searchStartText->text();
    int start_hr = start_time.split(":")[0].toInt();
    int start_min = start_time.split(":")[1].toInt();
    int start_sec = start_time.split(":")[2].toInt();
    int start_milisec = start_time.split(":")[3].toInt();
    int start_duration_millisec = start_hr*(1000*60*60) + start_min*(1000*60) + start_sec*(1000)+ start_milisec;

    ui->seekBar->setSliderPosition(start_duration_millisec);
    vplayer->setPosition(start_duration_millisec);
}

void MainWindow::on_pushButton_clicked()
{
    QString start_time = ui->searchStartText->text();
    int start_hr = start_time.split(":")[0].toInt();
    int start_min = start_time.split(":")[1].toInt();
    int start_sec = start_time.split(":")[2].toInt();
    int start_milisec = start_time.split(":")[3].toInt();
    int start_duration_millisec = start_hr*(1000*60*60) + start_min*(1000*60) + start_sec*(1000)+ start_milisec;
    m_audio_preview_start = start_duration_millisec;

    QString end_time = ui->searchEndText->text();
    int end_hr = end_time.split(":")[0].toInt();
    int end_min = end_time.split(":")[1].toInt();
    int end_sec = end_time.split(":")[2].toInt();
    int end_milisec = end_time.split(":")[3].toInt();
    int end_duration_millisec = end_hr*(1000*60*60) + end_min*(1000*60) + end_sec*(1000)+ end_milisec;
    m_audio_preview_end = end_duration_millisec;

    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(previewStop(qint64)));
    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(muteSearchedParts(qint64)));
    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(updateSeekBar(qint64)));
    QObject::connect(vplayer,SIGNAL(positionChanged(qint64)),this,SLOT(skipTrimmedParts(qint64)));

    vplayer->play();

}

void MainWindow::previewStop(qint64 position)
{
    int newPosition = position;


    if(position>=m_audio_preview_end)
    {

        vplayer->stop();
    }

}

void MainWindow::on_getAudioStart_clicked()
{
    int start_position = ui->seekBar->sliderPosition();
    int hr = start_position/(1000*60*60);
    int min = (start_position/(1000*60))%60;
    int sec = (start_position/(1000))%60;
    int milisec = start_position % 1000;
    ui->searchStartText->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));
}

void MainWindow::on_getAudioEnd_clicked()
{
    int start_position = ui->seekBar->sliderPosition();
    int hr = start_position/(1000*60*60);
    int min = (start_position/(1000*60))%60;
    int sec = (start_position/(1000))%60;
    int milisec = start_position % 1000;
    ui->searchEndText->setText(QString::number(hr)+":"+QString::number(min)+":"+QString::number(sec)+":"+QString::number(milisec));
}

void MainWindow::on_undoMute_clicked()
{
    m_datastorage->deleteMuteDetails(m_selected_mute_detail_index);
    updateMuteListTable();
}

void MainWindow::setAudioProgressBarMaxValue(int value)
{
    ui->audioProgressBar->setMaximum(value);
}

void MainWindow::updateAudioProgressBarValue(int value)
{
    ui->audioProgressBar->setValue(value);
}

void MainWindow::setVideoProgressBarMaxValue(int value)
{
    ui->videoProgressBar->setMaximum(value);
}

void MainWindow::updateVideoProgressBarValue(int value)
{
    ui->videoProgressBar->setValue(value);
}
