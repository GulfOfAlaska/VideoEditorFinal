/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExport;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_11;
    QVideoWidget *videoScreen;
    QFrame *frame_4;
    QGridLayout *gridLayout_12;
    QFrame *frame_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pauseVideo;
    QPushButton *stopVideo;
    QPushButton *playVideo;
    QSpacerItem *horizontalSpacer_3;
    QFrame *frame;
    QGridLayout *gridLayout_4;
    QSpacerItem *horizontalSpacer_2;
    QLabel *seekBarTime;
    QSlider *seekBar;
    QWidget *tab_6;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_7;
    QProgressBar *progressBar;
    QScrollArea *scrollArea_4;
    QWidget *scrollAreaWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *mainSWLabel;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_8;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *mainSpgmLabel;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QVBoxLayout *verticalLayout_4;
    QLabel *secondarySpgmLabel;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidget_4;
    QWidget *dockWidgetContents_13;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget_3;
    QWidget *tab_2;
    QGridLayout *gridLayout_7;
    QTabWidget *tabWidget_4;
    QWidget *tab_9;
    QGridLayout *gridLayout_8;
    QFrame *frame_5;
    QGridLayout *gridLayout_13;
    QFrame *frame_6;
    QGridLayout *gridLayout_5;
    QLineEdit *trimEnd;
    QPushButton *deleteTrim;
    QPushButton *cutVideo;
    QLineEdit *trimStart;
    QLabel *label;
    QLineEdit *trimName;
    QPushButton *getTrimEnd;
    QPushButton *getTrimStart;
    QFrame *frame_7;
    QGridLayout *gridLayout_14;
    QFrame *frame_11;
    QGridLayout *gridLayout_19;
    QTableWidget *trimListTable;
    QSpacerItem *horizontalSpacer_4;
    QWidget *tab_10;
    QGridLayout *gridLayout_9;
    QFrame *frame_13;
    QGridLayout *gridLayout_21;
    QVideoWidget *JoinPreviewVideoScreen;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *JoinPreviewVPlay;
    QPushButton *JoinPreviewVStop;
    QPushButton *JoinPreviewVPause;
    QFrame *frame_14;
    QGridLayout *gridLayout_22;
    QTableWidget *joinListTable;
    QFrame *frame_12;
    QGridLayout *gridLayout_20;
    QFrame *frame_10;
    QGridLayout *gridLayout_16;
    QPushButton *chooseVideoFromFile;
    QPushButton *insertVideoUndo;
    QPushButton *insertVideo;
    QSpacerItem *verticalSpacer_7;
    QSpacerItem *verticalSpacer_8;
    QFrame *frame_15;
    QGridLayout *gridLayout_17;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QLineEdit *insertNote;
    QLabel *label_2;
    QPushButton *getInsertTime;
    QLineEdit *insertText;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_4;
    QWidget *tab_8;
    QGridLayout *gridLayout_6;
    QFrame *frame_18;
    QGridLayout *gridLayout_24;
    QFrame *frame_16;
    QGridLayout *gridLayout_18;
    QPushButton *pushButton;
    QPushButton *searchAudio;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_6;
    QPushButton *chooseAudio;
    QPushButton *muteAudioPart;
    QPushButton *undoMute;
    QFrame *frame_17;
    QGridLayout *gridLayout_23;
    QLineEdit *searchStartText;
    QPushButton *getAudioEnd;
    QLineEdit *searchEndText;
    QPushButton *getAudioStart;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_5;
    QPushButton *pushButton_2;
    QFrame *frame_8;
    QGridLayout *gridLayout_15;
    QTableWidget *audioSearchTable;
    QLabel *label_4;
    QLabel *label_3;
    QTableWidget *muteListTable;
    QFrame *frame_3;
    QGridLayout *gridLayout_10;
    QDockWidget *dockWidget_2;
    QWidget *dockWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;
    QLabel *processUpdateLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(838, 583);
        MainWindow->setDockNestingEnabled(true);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setTabPosition(QTabWidget::North);
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        gridLayout_11 = new QGridLayout(tab_5);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        videoScreen = new QVideoWidget(tab_5);
        videoScreen->setObjectName(QStringLiteral("videoScreen"));
        videoScreen->setStyleSheet(QStringLiteral(""));

        gridLayout_11->addWidget(videoScreen, 1, 0, 2, 1);

        frame_4 = new QFrame(tab_5);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy);
        frame_4->setFrameShape(QFrame::NoFrame);
        frame_4->setFrameShadow(QFrame::Raised);
        gridLayout_12 = new QGridLayout(frame_4);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        gridLayout_12->setVerticalSpacing(0);
        gridLayout_12->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(frame_4);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame_2);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        pauseVideo = new QPushButton(frame_2);
        pauseVideo->setObjectName(QStringLiteral("pauseVideo"));

        gridLayout_2->addWidget(pauseVideo, 1, 3, 1, 1);

        stopVideo = new QPushButton(frame_2);
        stopVideo->setObjectName(QStringLiteral("stopVideo"));

        gridLayout_2->addWidget(stopVideo, 1, 2, 1, 1);

        playVideo = new QPushButton(frame_2);
        playVideo->setObjectName(QStringLiteral("playVideo"));

        gridLayout_2->addWidget(playVideo, 1, 1, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 1, 0, 1, 1);


        gridLayout_12->addWidget(frame_2, 2, 0, 1, 1);

        frame = new QFrame(frame_4);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setVerticalSpacing(0);
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(791, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        seekBarTime = new QLabel(frame);
        seekBarTime->setObjectName(QStringLiteral("seekBarTime"));

        gridLayout_4->addWidget(seekBarTime, 0, 0, 1, 1);


        gridLayout_12->addWidget(frame, 0, 0, 1, 1);

        seekBar = new QSlider(frame_4);
        seekBar->setObjectName(QStringLiteral("seekBar"));
        seekBar->setMaximum(99);
        seekBar->setPageStep(1);
        seekBar->setOrientation(Qt::Horizontal);
        seekBar->setTickPosition(QSlider::NoTicks);

        gridLayout_12->addWidget(seekBar, 1, 0, 1, 1);


        gridLayout_11->addWidget(frame_4, 3, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        verticalLayout_5 = new QVBoxLayout(tab_6);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        tabWidget_2 = new QTabWidget(tab_6);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tabWidget_2->setTabShape(QTabWidget::Rounded);
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        verticalLayout_7 = new QVBoxLayout(tab_3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        progressBar = new QProgressBar(tab_3);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        verticalLayout_7->addWidget(progressBar);

        scrollArea_4 = new QScrollArea(tab_3);
        scrollArea_4->setObjectName(QStringLiteral("scrollArea_4"));
        scrollArea_4->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QStringLiteral("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 680, 134));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        mainSWLabel = new QLabel(scrollAreaWidgetContents_4);
        mainSWLabel->setObjectName(QStringLiteral("mainSWLabel"));

        verticalLayout_2->addWidget(mainSWLabel);

        scrollArea_4->setWidget(scrollAreaWidgetContents_4);

        verticalLayout_7->addWidget(scrollArea_4);

        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        verticalLayout_8 = new QVBoxLayout(tab_4);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        scrollArea_2 = new QScrollArea(tab_4);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 680, 77));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        mainSpgmLabel = new QLabel(scrollAreaWidgetContents_2);
        mainSpgmLabel->setObjectName(QStringLiteral("mainSpgmLabel"));

        verticalLayout_3->addWidget(mainSpgmLabel);

        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        verticalLayout_8->addWidget(scrollArea_2);

        scrollArea_3 = new QScrollArea(tab_4);
        scrollArea_3->setObjectName(QStringLiteral("scrollArea_3"));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QStringLiteral("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 680, 76));
        verticalLayout_4 = new QVBoxLayout(scrollAreaWidgetContents_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        secondarySpgmLabel = new QLabel(scrollAreaWidgetContents_3);
        secondarySpgmLabel->setObjectName(QStringLiteral("secondarySpgmLabel"));

        verticalLayout_4->addWidget(secondarySpgmLabel);

        scrollArea_3->setWidget(scrollAreaWidgetContents_3);

        verticalLayout_8->addWidget(scrollArea_3);

        tabWidget_2->addTab(tab_4, QString());

        verticalLayout_5->addWidget(tabWidget_2);

        tabWidget->addTab(tab_6, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 838, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        dockWidget_4 = new QDockWidget(MainWindow);
        dockWidget_4->setObjectName(QStringLiteral("dockWidget_4"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dockWidget_4->sizePolicy().hasHeightForWidth());
        dockWidget_4->setSizePolicy(sizePolicy2);
        dockWidget_4->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
        dockWidgetContents_13 = new QWidget();
        dockWidgetContents_13->setObjectName(QStringLiteral("dockWidgetContents_13"));
        gridLayout = new QGridLayout(dockWidgetContents_13);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget_3 = new QTabWidget(dockWidgetContents_13);
        tabWidget_3->setObjectName(QStringLiteral("tabWidget_3"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_7 = new QGridLayout(tab_2);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        tabWidget_4 = new QTabWidget(tab_2);
        tabWidget_4->setObjectName(QStringLiteral("tabWidget_4"));
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        gridLayout_8 = new QGridLayout(tab_9);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        frame_5 = new QFrame(tab_9);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        sizePolicy.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy);
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        gridLayout_13 = new QGridLayout(frame_5);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        gridLayout_13->setHorizontalSpacing(9);
        gridLayout_13->setVerticalSpacing(0);
        gridLayout_13->setContentsMargins(0, 0, 0, 0);

        gridLayout_8->addWidget(frame_5, 1, 0, 1, 1);

        frame_6 = new QFrame(tab_9);
        frame_6->setObjectName(QStringLiteral("frame_6"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy3);
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        gridLayout_5 = new QGridLayout(frame_6);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setVerticalSpacing(0);
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        trimEnd = new QLineEdit(frame_6);
        trimEnd->setObjectName(QStringLiteral("trimEnd"));
        sizePolicy3.setHeightForWidth(trimEnd->sizePolicy().hasHeightForWidth());
        trimEnd->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(trimEnd, 2, 3, 1, 1);

        deleteTrim = new QPushButton(frame_6);
        deleteTrim->setObjectName(QStringLiteral("deleteTrim"));

        gridLayout_5->addWidget(deleteTrim, 5, 1, 1, 1);

        cutVideo = new QPushButton(frame_6);
        cutVideo->setObjectName(QStringLiteral("cutVideo"));
        sizePolicy3.setHeightForWidth(cutVideo->sizePolicy().hasHeightForWidth());
        cutVideo->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(cutVideo, 4, 1, 1, 1);

        trimStart = new QLineEdit(frame_6);
        trimStart->setObjectName(QStringLiteral("trimStart"));
        sizePolicy3.setHeightForWidth(trimStart->sizePolicy().hasHeightForWidth());
        trimStart->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(trimStart, 1, 3, 1, 1);

        label = new QLabel(frame_6);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label, 0, 1, 1, 1);

        trimName = new QLineEdit(frame_6);
        trimName->setObjectName(QStringLiteral("trimName"));
        sizePolicy3.setHeightForWidth(trimName->sizePolicy().hasHeightForWidth());
        trimName->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(trimName, 0, 3, 1, 1);

        getTrimEnd = new QPushButton(frame_6);
        getTrimEnd->setObjectName(QStringLiteral("getTrimEnd"));
        sizePolicy3.setHeightForWidth(getTrimEnd->sizePolicy().hasHeightForWidth());
        getTrimEnd->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(getTrimEnd, 2, 1, 1, 1);

        getTrimStart = new QPushButton(frame_6);
        getTrimStart->setObjectName(QStringLiteral("getTrimStart"));
        sizePolicy3.setHeightForWidth(getTrimStart->sizePolicy().hasHeightForWidth());
        getTrimStart->setSizePolicy(sizePolicy3);

        gridLayout_5->addWidget(getTrimStart, 1, 1, 1, 1);

        trimStart->raise();
        getTrimStart->raise();
        getTrimEnd->raise();
        trimEnd->raise();
        cutVideo->raise();
        deleteTrim->raise();
        label->raise();
        trimName->raise();

        gridLayout_8->addWidget(frame_6, 0, 0, 1, 1);

        frame_7 = new QFrame(tab_9);
        frame_7->setObjectName(QStringLiteral("frame_7"));
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        gridLayout_14 = new QGridLayout(frame_7);
        gridLayout_14->setSpacing(6);
        gridLayout_14->setContentsMargins(11, 11, 11, 11);
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        gridLayout_14->setVerticalSpacing(0);
        gridLayout_14->setContentsMargins(0, 0, 0, 0);

        gridLayout_8->addWidget(frame_7, 0, 2, 1, 1);

        frame_11 = new QFrame(tab_9);
        frame_11->setObjectName(QStringLiteral("frame_11"));
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        gridLayout_19 = new QGridLayout(frame_11);
        gridLayout_19->setSpacing(6);
        gridLayout_19->setContentsMargins(11, 11, 11, 11);
        gridLayout_19->setObjectName(QStringLiteral("gridLayout_19"));
        trimListTable = new QTableWidget(frame_11);
        if (trimListTable->columnCount() < 3)
            trimListTable->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        trimListTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        trimListTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        trimListTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        trimListTable->setObjectName(QStringLiteral("trimListTable"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(trimListTable->sizePolicy().hasHeightForWidth());
        trimListTable->setSizePolicy(sizePolicy4);
        trimListTable->setColumnCount(3);

        gridLayout_19->addWidget(trimListTable, 0, 0, 1, 1);


        gridLayout_8->addWidget(frame_11, 0, 1, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_4, 0, 3, 1, 1);

        tabWidget_4->addTab(tab_9, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName(QStringLiteral("tab_10"));
        gridLayout_9 = new QGridLayout(tab_10);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        frame_13 = new QFrame(tab_10);
        frame_13->setObjectName(QStringLiteral("frame_13"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        gridLayout_21 = new QGridLayout(frame_13);
        gridLayout_21->setSpacing(0);
        gridLayout_21->setContentsMargins(11, 11, 11, 11);
        gridLayout_21->setObjectName(QStringLiteral("gridLayout_21"));
        gridLayout_21->setContentsMargins(0, 0, 0, 0);
        JoinPreviewVideoScreen = new QVideoWidget(frame_13);
        JoinPreviewVideoScreen->setObjectName(QStringLiteral("JoinPreviewVideoScreen"));
        JoinPreviewVideoScreen->setStyleSheet(QStringLiteral(""));

        gridLayout_21->addWidget(JoinPreviewVideoScreen, 0, 0, 1, 1);

        frame_9 = new QFrame(frame_13);
        frame_9->setObjectName(QStringLiteral("frame_9"));
        sizePolicy3.setHeightForWidth(frame_9->sizePolicy().hasHeightForWidth());
        frame_9->setSizePolicy(sizePolicy3);
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(frame_9);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        JoinPreviewVPlay = new QPushButton(frame_9);
        JoinPreviewVPlay->setObjectName(QStringLiteral("JoinPreviewVPlay"));

        horizontalLayout_2->addWidget(JoinPreviewVPlay);

        JoinPreviewVStop = new QPushButton(frame_9);
        JoinPreviewVStop->setObjectName(QStringLiteral("JoinPreviewVStop"));

        horizontalLayout_2->addWidget(JoinPreviewVStop);

        JoinPreviewVPause = new QPushButton(frame_9);
        JoinPreviewVPause->setObjectName(QStringLiteral("JoinPreviewVPause"));

        horizontalLayout_2->addWidget(JoinPreviewVPause);


        gridLayout_21->addWidget(frame_9, 1, 0, 1, 1);


        gridLayout_9->addWidget(frame_13, 0, 2, 1, 1);

        frame_14 = new QFrame(tab_10);
        frame_14->setObjectName(QStringLiteral("frame_14"));
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        gridLayout_22 = new QGridLayout(frame_14);
        gridLayout_22->setSpacing(0);
        gridLayout_22->setContentsMargins(11, 11, 11, 11);
        gridLayout_22->setObjectName(QStringLiteral("gridLayout_22"));
        gridLayout_22->setContentsMargins(0, 0, 0, 0);
        joinListTable = new QTableWidget(frame_14);
        joinListTable->setObjectName(QStringLiteral("joinListTable"));
        sizePolicy2.setHeightForWidth(joinListTable->sizePolicy().hasHeightForWidth());
        joinListTable->setSizePolicy(sizePolicy2);

        gridLayout_22->addWidget(joinListTable, 0, 0, 1, 1);


        gridLayout_9->addWidget(frame_14, 0, 1, 1, 1);

        frame_12 = new QFrame(tab_10);
        frame_12->setObjectName(QStringLiteral("frame_12"));
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        gridLayout_20 = new QGridLayout(frame_12);
        gridLayout_20->setSpacing(0);
        gridLayout_20->setContentsMargins(11, 11, 11, 11);
        gridLayout_20->setObjectName(QStringLiteral("gridLayout_20"));
        gridLayout_20->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(frame_12);
        frame_10->setObjectName(QStringLiteral("frame_10"));
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        gridLayout_16 = new QGridLayout(frame_10);
        gridLayout_16->setSpacing(0);
        gridLayout_16->setContentsMargins(11, 11, 11, 11);
        gridLayout_16->setObjectName(QStringLiteral("gridLayout_16"));
        gridLayout_16->setContentsMargins(0, 0, 0, 0);
        chooseVideoFromFile = new QPushButton(frame_10);
        chooseVideoFromFile->setObjectName(QStringLiteral("chooseVideoFromFile"));
        sizePolicy3.setHeightForWidth(chooseVideoFromFile->sizePolicy().hasHeightForWidth());
        chooseVideoFromFile->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(chooseVideoFromFile, 1, 0, 1, 1);

        insertVideoUndo = new QPushButton(frame_10);
        insertVideoUndo->setObjectName(QStringLiteral("insertVideoUndo"));
        sizePolicy3.setHeightForWidth(insertVideoUndo->sizePolicy().hasHeightForWidth());
        insertVideoUndo->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(insertVideoUndo, 2, 0, 1, 1);

        insertVideo = new QPushButton(frame_10);
        insertVideo->setObjectName(QStringLiteral("insertVideo"));
        sizePolicy3.setHeightForWidth(insertVideo->sizePolicy().hasHeightForWidth());
        insertVideo->setSizePolicy(sizePolicy3);

        gridLayout_16->addWidget(insertVideo, 3, 0, 1, 1);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_7, 4, 0, 1, 1);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_16->addItem(verticalSpacer_8, 0, 0, 1, 1);


        gridLayout_20->addWidget(frame_10, 1, 0, 1, 1);

        frame_15 = new QFrame(frame_12);
        frame_15->setObjectName(QStringLiteral("frame_15"));
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        gridLayout_17 = new QGridLayout(frame_15);
        gridLayout_17->setSpacing(0);
        gridLayout_17->setContentsMargins(11, 11, 11, 11);
        gridLayout_17->setObjectName(QStringLiteral("gridLayout_17"));
        gridLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_9, 0, 0, 1, 1);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_10, 0, 2, 1, 1);

        insertNote = new QLineEdit(frame_15);
        insertNote->setObjectName(QStringLiteral("insertNote"));
        sizePolicy3.setHeightForWidth(insertNote->sizePolicy().hasHeightForWidth());
        insertNote->setSizePolicy(sizePolicy3);

        gridLayout_17->addWidget(insertNote, 1, 2, 1, 1);

        label_2 = new QLabel(frame_15);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy5);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_17->addWidget(label_2, 1, 0, 1, 2);

        getInsertTime = new QPushButton(frame_15);
        getInsertTime->setObjectName(QStringLiteral("getInsertTime"));
        sizePolicy3.setHeightForWidth(getInsertTime->sizePolicy().hasHeightForWidth());
        getInsertTime->setSizePolicy(sizePolicy3);

        gridLayout_17->addWidget(getInsertTime, 2, 0, 1, 1);

        insertText = new QLineEdit(frame_15);
        insertText->setObjectName(QStringLiteral("insertText"));
        sizePolicy3.setHeightForWidth(insertText->sizePolicy().hasHeightForWidth());
        insertText->setSizePolicy(sizePolicy3);

        gridLayout_17->addWidget(insertText, 2, 1, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer, 3, 2, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_17->addItem(verticalSpacer_4, 3, 0, 1, 1);


        gridLayout_20->addWidget(frame_15, 1, 1, 1, 1);


        gridLayout_9->addWidget(frame_12, 0, 0, 1, 1);

        tabWidget_4->addTab(tab_10, QString());

        gridLayout_7->addWidget(tabWidget_4, 0, 0, 1, 1);

        tabWidget_3->addTab(tab_2, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        gridLayout_6 = new QGridLayout(tab_8);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frame_18 = new QFrame(tab_8);
        frame_18->setObjectName(QStringLiteral("frame_18"));
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        gridLayout_24 = new QGridLayout(frame_18);
        gridLayout_24->setSpacing(0);
        gridLayout_24->setContentsMargins(11, 11, 11, 11);
        gridLayout_24->setObjectName(QStringLiteral("gridLayout_24"));
        gridLayout_24->setContentsMargins(0, 0, 0, 0);
        frame_16 = new QFrame(frame_18);
        frame_16->setObjectName(QStringLiteral("frame_16"));
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        gridLayout_18 = new QGridLayout(frame_16);
        gridLayout_18->setSpacing(0);
        gridLayout_18->setContentsMargins(11, 11, 11, 11);
        gridLayout_18->setObjectName(QStringLiteral("gridLayout_18"));
        gridLayout_18->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(frame_16);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy5.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy5);

        gridLayout_18->addWidget(pushButton, 0, 1, 1, 1);

        searchAudio = new QPushButton(frame_16);
        searchAudio->setObjectName(QStringLiteral("searchAudio"));
        sizePolicy5.setHeightForWidth(searchAudio->sizePolicy().hasHeightForWidth());
        searchAudio->setSizePolicy(sizePolicy5);

        gridLayout_18->addWidget(searchAudio, 1, 1, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_3, 3, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_18->addItem(verticalSpacer_6, 3, 1, 1, 1);

        chooseAudio = new QPushButton(frame_16);
        chooseAudio->setObjectName(QStringLiteral("chooseAudio"));
        sizePolicy5.setHeightForWidth(chooseAudio->sizePolicy().hasHeightForWidth());
        chooseAudio->setSizePolicy(sizePolicy5);

        gridLayout_18->addWidget(chooseAudio, 0, 0, 1, 1);

        muteAudioPart = new QPushButton(frame_16);
        muteAudioPart->setObjectName(QStringLiteral("muteAudioPart"));
        sizePolicy5.setHeightForWidth(muteAudioPart->sizePolicy().hasHeightForWidth());
        muteAudioPart->setSizePolicy(sizePolicy5);

        gridLayout_18->addWidget(muteAudioPart, 1, 0, 1, 1);

        undoMute = new QPushButton(frame_16);
        undoMute->setObjectName(QStringLiteral("undoMute"));

        gridLayout_18->addWidget(undoMute, 2, 0, 1, 1);


        gridLayout_24->addWidget(frame_16, 1, 0, 1, 1);

        frame_17 = new QFrame(frame_18);
        frame_17->setObjectName(QStringLiteral("frame_17"));
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        gridLayout_23 = new QGridLayout(frame_17);
        gridLayout_23->setSpacing(0);
        gridLayout_23->setContentsMargins(11, 11, 11, 11);
        gridLayout_23->setObjectName(QStringLiteral("gridLayout_23"));
        gridLayout_23->setContentsMargins(0, 0, 0, 0);
        searchStartText = new QLineEdit(frame_17);
        searchStartText->setObjectName(QStringLiteral("searchStartText"));
        sizePolicy5.setHeightForWidth(searchStartText->sizePolicy().hasHeightForWidth());
        searchStartText->setSizePolicy(sizePolicy5);

        gridLayout_23->addWidget(searchStartText, 1, 1, 1, 1);

        getAudioEnd = new QPushButton(frame_17);
        getAudioEnd->setObjectName(QStringLiteral("getAudioEnd"));
        sizePolicy3.setHeightForWidth(getAudioEnd->sizePolicy().hasHeightForWidth());
        getAudioEnd->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(getAudioEnd, 2, 0, 1, 1);

        searchEndText = new QLineEdit(frame_17);
        searchEndText->setObjectName(QStringLiteral("searchEndText"));
        sizePolicy5.setHeightForWidth(searchEndText->sizePolicy().hasHeightForWidth());
        searchEndText->setSizePolicy(sizePolicy5);

        gridLayout_23->addWidget(searchEndText, 2, 1, 1, 1);

        getAudioStart = new QPushButton(frame_17);
        getAudioStart->setObjectName(QStringLiteral("getAudioStart"));
        sizePolicy3.setHeightForWidth(getAudioStart->sizePolicy().hasHeightForWidth());
        getAudioStart->setSizePolicy(sizePolicy3);

        gridLayout_23->addWidget(getAudioStart, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_23->addItem(verticalSpacer_2, 0, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_23->addItem(verticalSpacer_5, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(frame_17);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_23->addWidget(pushButton_2, 1, 2, 1, 1);


        gridLayout_24->addWidget(frame_17, 0, 0, 1, 1);


        gridLayout_6->addWidget(frame_18, 0, 0, 1, 1);

        frame_8 = new QFrame(tab_8);
        frame_8->setObjectName(QStringLiteral("frame_8"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        gridLayout_15 = new QGridLayout(frame_8);
        gridLayout_15->setSpacing(0);
        gridLayout_15->setContentsMargins(11, 11, 11, 11);
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        gridLayout_15->setContentsMargins(0, 0, 0, 0);
        audioSearchTable = new QTableWidget(frame_8);
        if (audioSearchTable->columnCount() < 2)
            audioSearchTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        audioSearchTable->setHorizontalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        audioSearchTable->setHorizontalHeaderItem(1, __qtablewidgetitem4);
        audioSearchTable->setObjectName(QStringLiteral("audioSearchTable"));

        gridLayout_15->addWidget(audioSearchTable, 1, 0, 1, 1);

        label_4 = new QLabel(frame_8);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_15->addWidget(label_4, 0, 1, 1, 1);

        label_3 = new QLabel(frame_8);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_15->addWidget(label_3, 0, 0, 1, 1);

        muteListTable = new QTableWidget(frame_8);
        if (muteListTable->columnCount() < 2)
            muteListTable->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        muteListTable->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        muteListTable->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        muteListTable->setObjectName(QStringLiteral("muteListTable"));

        gridLayout_15->addWidget(muteListTable, 1, 1, 1, 1);


        gridLayout_6->addWidget(frame_8, 0, 3, 1, 1);

        frame_3 = new QFrame(tab_8);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        sizePolicy3.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy3);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        gridLayout_10 = new QGridLayout(frame_3);
        gridLayout_10->setSpacing(0);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        gridLayout_10->setContentsMargins(0, 0, 0, 0);

        gridLayout_6->addWidget(frame_3, 0, 1, 1, 1);

        tabWidget_3->addTab(tab_8, QString());

        gridLayout->addWidget(tabWidget_3, 1, 0, 1, 1);

        dockWidget_4->setWidget(dockWidgetContents_13);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_4);
        dockWidget_2 = new QDockWidget(MainWindow);
        dockWidget_2->setObjectName(QStringLiteral("dockWidget_2"));
        sizePolicy2.setHeightForWidth(dockWidget_2->sizePolicy().hasHeightForWidth());
        dockWidget_2->setSizePolicy(sizePolicy2);
        dockWidget_2->setAutoFillBackground(false);
        dockWidget_2->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        dockWidget_2->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(dockWidgetContents_2);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 69, 227));
        scrollAreaWidgetContents->setLayoutDirection(Qt::LeftToRight);
        scrollAreaWidgetContents->setStyleSheet(QStringLiteral("border-color: rgb(0, 0, 0);"));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        processUpdateLabel = new QLabel(scrollAreaWidgetContents);
        processUpdateLabel->setObjectName(QStringLiteral("processUpdateLabel"));
        processUpdateLabel->setWordWrap(true);

        gridLayout_3->addWidget(processUpdateLabel, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        dockWidget_2->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_2);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExport);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        tabWidget_2->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(1);
        tabWidget_4->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        pauseVideo->setText(QApplication::translate("MainWindow", "Pause", 0));
        stopVideo->setText(QApplication::translate("MainWindow", "Stop", 0));
        playVideo->setText(QApplication::translate("MainWindow", "Play", 0));
        seekBarTime->setText(QApplication::translate("MainWindow", "00:00:00", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Video", 0));
        mainSWLabel->setText(QApplication::translate("MainWindow", "Orignal sound wave", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("MainWindow", "SoundWave", 0));
        mainSpgmLabel->setText(QApplication::translate("MainWindow", "FFTed spectogram of original wave", 0));
        secondarySpgmLabel->setText(QApplication::translate("MainWindow", "FFTed spectogram of what to search for", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("MainWindow", "Spectrums", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Audio", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        dockWidget_4->setWindowTitle(QApplication::translate("MainWindow", "Tools", 0));
        deleteTrim->setText(QApplication::translate("MainWindow", "Undo", 0));
        cutVideo->setText(QApplication::translate("MainWindow", "Trim", 0));
        label->setText(QApplication::translate("MainWindow", "Trim Note:", 0));
        getTrimEnd->setText(QApplication::translate("MainWindow", "End", 0));
        getTrimStart->setText(QApplication::translate("MainWindow", "Start", 0));
        QTableWidgetItem *___qtablewidgetitem = trimListTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Start ", 0));
        QTableWidgetItem *___qtablewidgetitem1 = trimListTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "End", 0));
        QTableWidgetItem *___qtablewidgetitem2 = trimListTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Name", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_9), QApplication::translate("MainWindow", "Trim", 0));
        JoinPreviewVPlay->setText(QApplication::translate("MainWindow", "Play", 0));
        JoinPreviewVStop->setText(QApplication::translate("MainWindow", "Stop", 0));
        JoinPreviewVPause->setText(QApplication::translate("MainWindow", "Pause", 0));
        chooseVideoFromFile->setText(QApplication::translate("MainWindow", "Get Clip", 0));
        insertVideoUndo->setText(QApplication::translate("MainWindow", "Undo", 0));
        insertVideo->setText(QApplication::translate("MainWindow", "Insert", 0));
        label_2->setText(QApplication::translate("MainWindow", "Insert Note:", 0));
        getInsertTime->setText(QApplication::translate("MainWindow", "Insert Time", 0));
        tabWidget_4->setTabText(tabWidget_4->indexOf(tab_10), QApplication::translate("MainWindow", "Insert/join", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_2), QApplication::translate("MainWindow", "Edit Video", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Preview ", 0));
        searchAudio->setText(QApplication::translate("MainWindow", "Search", 0));
        chooseAudio->setText(QApplication::translate("MainWindow", "Choose File", 0));
        muteAudioPart->setText(QApplication::translate("MainWindow", "Mute Part", 0));
        undoMute->setText(QApplication::translate("MainWindow", "Undo", 0));
        getAudioEnd->setText(QApplication::translate("MainWindow", "End", 0));
        getAudioStart->setText(QApplication::translate("MainWindow", "Start", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Go To", 0));
        QTableWidgetItem *___qtablewidgetitem3 = audioSearchTable->horizontalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Start", 0));
        QTableWidgetItem *___qtablewidgetitem4 = audioSearchTable->horizontalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "End", 0));
        label_4->setText(QApplication::translate("MainWindow", "Mute list:", 0));
        label_3->setText(QApplication::translate("MainWindow", "Search Results:", 0));
        QTableWidgetItem *___qtablewidgetitem5 = muteListTable->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Start", 0));
        QTableWidgetItem *___qtablewidgetitem6 = muteListTable->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "End", 0));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "Edit Audio", 0));
        dockWidget_2->setWindowTitle(QApplication::translate("MainWindow", "Console", 0));
        processUpdateLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
