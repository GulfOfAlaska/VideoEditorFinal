#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "libsndfile/include/sndfile.hh"
#include "datastorage.h"
#include "fftw/fftw3.h"
#include <QMediaPlayer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void updateVideoUiLabel(QImage *frame);
    void updateUiLabel(QString text);
    void updateMainSpgmLabel(fftw_complex *fftout, int num_items);
    void updateSecondarySpgmLabel(fftw_complex *fftout, int num_items);
    void updateMainSWLabel(double *buf, int num_items);
    void updateCrossCorrelationLabel(double *buf, int num_items);
    void updateAudioSearchList();

private slots:
    void on_actionOpen_triggered();
    void on_chooseAudio_clicked();
    void on_searchAudio_clicked();
    void on_seekBar_sliderMoved(int position);
    void updateSeekBar(qint64 position);
    void updateVideoDuration(qint64 duration);
    void initMainVideo();
    void on_getTrimStart_clicked();
    void on_getTrimEnd_clicked();
    void on_cutVideo_clicked();
    void skipTrimmedParts(qint64 position);
    void muteSearchedParts(qint64 position);
    void on_playVideo_clicked();
    void on_stopVideo_clicked();
    void on_pauseVideo_clicked();
    void on_audioSearchTable_cellClicked(int row, int column);
    void on_actionExport_triggered();
    void on_trimListTable_cellClicked(int row, int column);
    void on_deleteTrim_clicked();
    void on_chooseVideoFromFile_clicked();
    void on_JoinPreviewVPlay_clicked();
    void on_JoinPreviewVStop_clicked();
    void on_JoinPreviewVPause_clicked();
    void on_getInsertTime_clicked();
    void on_insertVideo_clicked();
    void on_joinListTable_cellClicked(int row, int column);
    void on_insertVideoUndo_clicked();
    void on_muteAudioPart_clicked();
    void on_muteListTable_cellClicked(int row, int column);
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void previewStop(qint64 position);
    void on_getAudioStart_clicked();
    void on_getAudioEnd_clicked();
    void on_undoMute_clicked();

private:
    Ui::MainWindow *ui;
    QString m_main_filepath;
    QString m_secondary_filepath;
    dataStorage* m_datastorage;
    QMediaPlayer* vplayer;
    QMediaPlayer* aplayer;
    QMediaPlayer* joinPreviewVplayer;
    void updateTrimListTable();
    void updateJoinListTable();
    void updateMuteListTable();
    int m_selected_trim_detail_index;
    int m_selected_join_detail_index;
    int m_selected_search_detail_index;
    int m_selected_search_detail_start;
    int m_selected_search_detail_end;
    int m_audio_preview_start;
    int m_audio_preview_end;
    int m_selected_mute_detail_index;
    QString m_join_video_filepath;
};

#endif // MAINWINDOW_H
