/****************************************************************************
** Meta object code from reading C++ file 'engine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../RA/engine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'engine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Engine_t {
    QByteArrayData data[24];
    char stringdata[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Engine_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Engine_t qt_meta_stringdata_Engine = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Engine"
QT_MOC_LITERAL(1, 7, 13), // "processUpdate"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 4), // "text"
QT_MOC_LITERAL(4, 27, 14), // "mainSpgmUpdate"
QT_MOC_LITERAL(5, 42, 13), // "fftw_complex*"
QT_MOC_LITERAL(6, 56, 6), // "fftout"
QT_MOC_LITERAL(7, 63, 9), // "num_items"
QT_MOC_LITERAL(8, 73, 19), // "secondarySpgmUpdate"
QT_MOC_LITERAL(9, 93, 12), // "mainSWUpdate"
QT_MOC_LITERAL(10, 106, 7), // "double*"
QT_MOC_LITERAL(11, 114, 3), // "buf"
QT_MOC_LITERAL(12, 118, 10), // "corrUpdate"
QT_MOC_LITERAL(13, 129, 22), // "updateAudioSearchTable"
QT_MOC_LITERAL(14, 152, 7), // "started"
QT_MOC_LITERAL(15, 160, 8), // "finished"
QT_MOC_LITERAL(16, 169, 12), // "readFinished"
QT_MOC_LITERAL(17, 182, 7), // "GetData"
QT_MOC_LITERAL(18, 190, 22), // "DrawSpectogramFinished"
QT_MOC_LITERAL(19, 213, 11), // "ReadWavFile"
QT_MOC_LITERAL(20, 225, 11), // "SearchAudio"
QT_MOC_LITERAL(21, 237, 11), // "exportVideo"
QT_MOC_LITERAL(22, 249, 11), // "exportTrims"
QT_MOC_LITERAL(23, 261, 11) // "exportMutes"

    },
    "Engine\0processUpdate\0\0text\0mainSpgmUpdate\0"
    "fftw_complex*\0fftout\0num_items\0"
    "secondarySpgmUpdate\0mainSWUpdate\0"
    "double*\0buf\0corrUpdate\0updateAudioSearchTable\0"
    "started\0finished\0readFinished\0GetData\0"
    "DrawSpectogramFinished\0ReadWavFile\0"
    "SearchAudio\0exportVideo\0exportTrims\0"
    "exportMutes"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Engine[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    2,   97,    2, 0x06 /* Public */,
       8,    2,  102,    2, 0x06 /* Public */,
       9,    2,  107,    2, 0x06 /* Public */,
      12,    2,  112,    2, 0x06 /* Public */,
      13,    0,  117,    2, 0x06 /* Public */,
      14,    0,  118,    2, 0x06 /* Public */,
      15,    0,  119,    2, 0x06 /* Public */,
      16,    0,  120,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    0,  121,    2, 0x0a /* Public */,
      18,    0,  122,    2, 0x0a /* Public */,
      19,    0,  123,    2, 0x0a /* Public */,
      20,    0,  124,    2, 0x0a /* Public */,
      21,    0,  125,    2, 0x0a /* Public */,
      22,    0,  126,    2, 0x0a /* Public */,
      23,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 5, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,    7,
    QMetaType::Void, 0x80000000 | 10, QMetaType::Int,   11,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Engine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Engine *_t = static_cast<Engine *>(_o);
        switch (_id) {
        case 0: _t->processUpdate((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->mainSpgmUpdate((*reinterpret_cast< fftw_complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->secondarySpgmUpdate((*reinterpret_cast< fftw_complex*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->mainSWUpdate((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->corrUpdate((*reinterpret_cast< double*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->updateAudioSearchTable(); break;
        case 6: _t->started(); break;
        case 7: _t->finished(); break;
        case 8: _t->readFinished(); break;
        case 9: { int _r = _t->GetData();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 10: _t->DrawSpectogramFinished(); break;
        case 11: { int _r = _t->ReadWavFile();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        case 12: _t->SearchAudio(); break;
        case 13: _t->exportVideo(); break;
        case 14: _t->exportTrims(); break;
        case 15: _t->exportMutes(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Engine::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::processUpdate)) {
                *result = 0;
            }
        }
        {
            typedef void (Engine::*_t)(fftw_complex * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::mainSpgmUpdate)) {
                *result = 1;
            }
        }
        {
            typedef void (Engine::*_t)(fftw_complex * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::secondarySpgmUpdate)) {
                *result = 2;
            }
        }
        {
            typedef void (Engine::*_t)(double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::mainSWUpdate)) {
                *result = 3;
            }
        }
        {
            typedef void (Engine::*_t)(double * , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::corrUpdate)) {
                *result = 4;
            }
        }
        {
            typedef void (Engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::updateAudioSearchTable)) {
                *result = 5;
            }
        }
        {
            typedef void (Engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::started)) {
                *result = 6;
            }
        }
        {
            typedef void (Engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::finished)) {
                *result = 7;
            }
        }
        {
            typedef void (Engine::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Engine::readFinished)) {
                *result = 8;
            }
        }
    }
}

const QMetaObject Engine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Engine.data,
      qt_meta_data_Engine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Engine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Engine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Engine.stringdata))
        return static_cast<void*>(const_cast< Engine*>(this));
    return QObject::qt_metacast(_clname);
}

int Engine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void Engine::processUpdate(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Engine::mainSpgmUpdate(fftw_complex * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Engine::secondarySpgmUpdate(fftw_complex * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Engine::mainSWUpdate(double * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Engine::corrUpdate(double * _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Engine::updateAudioSearchTable()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Engine::started()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void Engine::finished()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void Engine::readFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
