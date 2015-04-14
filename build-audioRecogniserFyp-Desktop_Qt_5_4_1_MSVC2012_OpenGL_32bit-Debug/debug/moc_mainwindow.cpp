/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RA/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[56];
    char stringdata[1064];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 18), // "updateVideoUiLabel"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "QImage*"
QT_MOC_LITERAL(4, 39, 5), // "frame"
QT_MOC_LITERAL(5, 45, 13), // "updateUiLabel"
QT_MOC_LITERAL(6, 59, 4), // "text"
QT_MOC_LITERAL(7, 64, 19), // "updateMainSpgmLabel"
QT_MOC_LITERAL(8, 84, 13), // "fftw_complex*"
QT_MOC_LITERAL(9, 98, 6), // "fftout"
QT_MOC_LITERAL(10, 105, 9), // "num_items"
QT_MOC_LITERAL(11, 115, 24), // "updateSecondarySpgmLabel"
QT_MOC_LITERAL(12, 140, 17), // "updateMainSWLabel"
QT_MOC_LITERAL(13, 158, 7), // "double*"
QT_MOC_LITERAL(14, 166, 3), // "buf"
QT_MOC_LITERAL(15, 170, 27), // "updateCrossCorrelationLabel"
QT_MOC_LITERAL(16, 198, 21), // "updateAudioSearchList"
QT_MOC_LITERAL(17, 220, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(18, 244, 22), // "on_chooseAudio_clicked"
QT_MOC_LITERAL(19, 267, 22), // "on_searchAudio_clicked"
QT_MOC_LITERAL(20, 290, 22), // "on_seekBar_sliderMoved"
QT_MOC_LITERAL(21, 313, 8), // "position"
QT_MOC_LITERAL(22, 322, 13), // "updateSeekBar"
QT_MOC_LITERAL(23, 336, 19), // "updateVideoDuration"
QT_MOC_LITERAL(24, 356, 8), // "duration"
QT_MOC_LITERAL(25, 365, 13), // "initMainVideo"
QT_MOC_LITERAL(26, 379, 23), // "on_getTrimStart_clicked"
QT_MOC_LITERAL(27, 403, 21), // "on_getTrimEnd_clicked"
QT_MOC_LITERAL(28, 425, 19), // "on_cutVideo_clicked"
QT_MOC_LITERAL(29, 445, 16), // "skipTrimmedParts"
QT_MOC_LITERAL(30, 462, 17), // "muteSearchedParts"
QT_MOC_LITERAL(31, 480, 20), // "on_playVideo_clicked"
QT_MOC_LITERAL(32, 501, 20), // "on_stopVideo_clicked"
QT_MOC_LITERAL(33, 522, 21), // "on_pauseVideo_clicked"
QT_MOC_LITERAL(34, 544, 31), // "on_audioSearchTable_cellClicked"
QT_MOC_LITERAL(35, 576, 3), // "row"
QT_MOC_LITERAL(36, 580, 6), // "column"
QT_MOC_LITERAL(37, 587, 25), // "on_actionExport_triggered"
QT_MOC_LITERAL(38, 613, 28), // "on_trimListTable_cellClicked"
QT_MOC_LITERAL(39, 642, 21), // "on_deleteTrim_clicked"
QT_MOC_LITERAL(40, 664, 30), // "on_chooseVideoFromFile_clicked"
QT_MOC_LITERAL(41, 695, 27), // "on_JoinPreviewVPlay_clicked"
QT_MOC_LITERAL(42, 723, 27), // "on_JoinPreviewVStop_clicked"
QT_MOC_LITERAL(43, 751, 28), // "on_JoinPreviewVPause_clicked"
QT_MOC_LITERAL(44, 780, 24), // "on_getInsertTime_clicked"
QT_MOC_LITERAL(45, 805, 22), // "on_insertVideo_clicked"
QT_MOC_LITERAL(46, 828, 28), // "on_joinListTable_cellClicked"
QT_MOC_LITERAL(47, 857, 26), // "on_insertVideoUndo_clicked"
QT_MOC_LITERAL(48, 884, 24), // "on_muteAudioPart_clicked"
QT_MOC_LITERAL(49, 909, 28), // "on_muteListTable_cellClicked"
QT_MOC_LITERAL(50, 938, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(51, 962, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(52, 984, 11), // "previewStop"
QT_MOC_LITERAL(53, 996, 24), // "on_getAudioStart_clicked"
QT_MOC_LITERAL(54, 1021, 22), // "on_getAudioEnd_clicked"
QT_MOC_LITERAL(55, 1044, 19) // "on_undoMute_clicked"

    },
    "MainWindow\0updateVideoUiLabel\0\0QImage*\0"
    "frame\0updateUiLabel\0text\0updateMainSpgmLabel\0"
    "fftw_complex*\0fftout\0num_items\0"
    "updateSecondarySpgmLabel\0updateMainSWLabel\0"
    "double*\0buf\0updateCrossCorrelationLabel\0"
    "updateAudioSearchList\0on_actionOpen_triggered\0"
    "on_chooseAudio_clicked\0on_searchAudio_clicked\0"
    "on_seekBar_sliderMoved\0position\0"
    "updateSeekBar\0updateVideoDuration\0"
    "duration\0initMainVideo\0on_getTrimStart_clicked\0"
    "on_getTrimEnd_clicked\0on_cutVideo_clicked\0"
    "skipTrimmedParts\0muteSearchedParts\0"
    "on_playVideo_clicked\0on_stopVideo_clicked\0"
    "on_pauseVideo_clicked\0"
    "on_audioSearchTable_cellClicked\0row\0"
    "column\0on_actionExport_triggered\0"
    "on_trimListTable_cellClicked\0"
    "on_deleteTrim_clicked\0"
    "on_chooseVideoFromFile_clicked\0"
    "on_JoinPreviewVPlay_clicked\0"
    "on_JoinPreviewVStop_clicked\0"
    "on_JoinPreviewVPause_clicked\0"
    "on_getInsertTime_clicked\0"
    "on_insertVideo_clicked\0"
    "on_joinListTable_cellClicked\0"
    "on_insertVideoUndo_clicked\0"
    "on_muteAudioPart_clicked\0"
    "on_muteListTable_cellClicked\0"
    "on_pushButton_2_clicked\0on_pushButton_clicked\0"
    "previewStop\0on_getAudioStart_clicked\0"
    "on_getAudioEnd_clicked\0on_undoMute_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  224,    2, 0x0a /* Public */,
       5,    1,  227,    2, 0x0a /* Public */,
       7,    2,  230,    2, 0x0a /* Public */,
      11,    2,  235,    2, 0x0a /* Public */,
      12,    2,  240,    2, 0x0a /* Public */,
      15,    2,  245,    2, 0x0a /* Public */,
      16,    0,  250,    2, 0x0a /* Public */,
      17,    0,  251,    2, 0x08 /* Private */,
      18,    0,  252,    2, 0x08 /* Private */,
      19,    0,  253,    2, 0x08 /* Private */,
      20,    1,  254,    2, 0x08 /* Private */,
      22,    1,  257,    2, 0x08 /* Private */,
      23,    1,  260,    2, 0x08 /* Private */,
      25,    0,  263,    2, 0x08 /* Private */,
      26,    0,  264,    2, 0x08 /* Private */,
      27,    0,  265,    2, 0x08 /* Private */,
      28,    0,  266,    2, 0x08 /* Private */,
      29,    1,  267,    2, 0x08 /* Private */,
      30,    1,  270,    2, 0x08 /* Private */,
      31,    0,  273,    2, 0x08 /* Private */,
      32,    0,  274,    2, 0x08 /* Private */,
      33,    0,  275,    2, 0x08 /* Private */,
      34,    2,  276,    2, 0x08 /* Private */,
      37,    0,  281,    2, 0x08 /* Private */,
      38,    2,  282,    2, 0x08 /* Private */,
      39,    0,  287,    2, 0x08 /* Private */,
      40,    0,  288,    2, 0x08 /* Private */,
      41,    0,  289,    2, 0x08 /* Private */,
      42,    0,  290,    2, 0x08 /* Private */,
      43,    0,  291,    2, 0x08 /* Private */,
      44,    0,  292,    2, 0x08 /* Private */,
      45,    0,  293,    2, 0x08 /* Private */,
      46,    2,  294,    2, 0x08 /* Private */,
      47,    0,  299,    2, 0x08 /* Private */,
      48,    0,  300,    2, 0x08 /* Private */,
      49,    2,  301,    2, 0x08 /* Private */,
      50,    0,  306,    2, 0x08 /* Private */,
      51,    0,  307,    2, 0x08 /* Private */,
      52,    1,  308,    2, 0x08 /* Private */,
      53,    0,  311,    2, 0x08 /* Private */,
      54,    0,  312,    2, 0x08 /* Private */,
      55,    0,  313,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 8, QMetaType::Int,    9,   10,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   10,
    QMetaType::Void, 0x80000000 | 13, QMetaType::Int,   14,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::LongLong,   21,
    QMetaType::Void, QMetaType::LongLong,   24,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   21,
    QMetaType::Void, QMetaType::LongLong,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   35,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,   21,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->updateVideoUiLabel((*reinterpret_cast< QImage*(*)>(_a[1]))); break;
        case 1: _t->updateUiLabel((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updateMainSpgmLabel((*reinterpret_cast< fftw_complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->updateSecondarySpgmLabel((*reinterpret_cast< fftw_complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->updateMainSWLabel((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateCrossCorrelationLabel((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->updateAudioSearchList(); break;
        case 7: _t->on_actionOpen_triggered(); break;
        case 8: _t->on_chooseAudio_clicked(); break;
        case 9: _t->on_searchAudio_clicked(); break;
        case 10: _t->on_seekBar_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->updateSeekBar((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 12: _t->updateVideoDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 13: _t->initMainVideo(); break;
        case 14: _t->on_getTrimStart_clicked(); break;
        case 15: _t->on_getTrimEnd_clicked(); break;
        case 16: _t->on_cutVideo_clicked(); break;
        case 17: _t->skipTrimmedParts((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 18: _t->muteSearchedParts((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 19: _t->on_playVideo_clicked(); break;
        case 20: _t->on_stopVideo_clicked(); break;
        case 21: _t->on_pauseVideo_clicked(); break;
        case 22: _t->on_audioSearchTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 23: _t->on_actionExport_triggered(); break;
        case 24: _t->on_trimListTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 25: _t->on_deleteTrim_clicked(); break;
        case 26: _t->on_chooseVideoFromFile_clicked(); break;
        case 27: _t->on_JoinPreviewVPlay_clicked(); break;
        case 28: _t->on_JoinPreviewVStop_clicked(); break;
        case 29: _t->on_JoinPreviewVPause_clicked(); break;
        case 30: _t->on_getInsertTime_clicked(); break;
        case 31: _t->on_insertVideo_clicked(); break;
        case 32: _t->on_joinListTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 33: _t->on_insertVideoUndo_clicked(); break;
        case 34: _t->on_muteAudioPart_clicked(); break;
        case 35: _t->on_muteListTable_cellClicked((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 36: _t->on_pushButton_2_clicked(); break;
        case 37: _t->on_pushButton_clicked(); break;
        case 38: _t->previewStop((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 39: _t->on_getAudioStart_clicked(); break;
        case 40: _t->on_getAudioEnd_clicked(); break;
        case 41: _t->on_undoMute_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
