#-------------------------------------------------
#
# Project created by QtCreator 2015-02-02T00:31:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia multimediawidgets # TAKE NOTE: multimedia is here to enable usage of QSound!

TARGET = audioRecogniserFyp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    engine.cpp \
    datastorage.cpp \
    alglibmisc.cpp \
    fasttransforms.cpp \
    ap.cpp \
    alglibinternal.cpp \
    trimdetail.cpp

HEADERS  += mainwindow.h \
    engine.h \
    datastorage.h \
    ap.h \
    fasttransforms.h \
    alglibmisc.h \
    alglibinternal.h \
    trimdetail.h

FORMS    += mainwindow.ui

unix|win32: LIBS += -L$$PWD/libsndfile/lib/ -llibsndfile-1

INCLUDEPATH += $$PWD/libsndfile/include
DEPENDPATH += $$PWD/libsndfile/include

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/libsndfile/lib/libsndfile-1.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/libsndfile/lib/liblibsndfile-1.a

unix|win32: LIBS += -L$$PWD/fftw/ -llibfftw3-3

INCLUDEPATH += $$PWD/fftw
DEPENDPATH += $$PWD/fftw

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/fftw/libfftw3-3.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/fftw/liblibfftw3-3.a

unix|win32: LIBS += -L$$PWD/fftw/ -llibfftw3f-3

INCLUDEPATH += $$PWD/fftw
DEPENDPATH += $$PWD/fftw

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/fftw/libfftw3f-3.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/fftw/liblibfftw3f-3.a

unix|win32: LIBS += -L$$PWD/fftw/ -llibfftw3l-3

INCLUDEPATH += $$PWD/fftw
DEPENDPATH += $$PWD/fftw

win32:!win32-g++: PRE_TARGETDEPS += $$PWD/fftw/libfftw3l-3.lib
else:unix|win32-g++: PRE_TARGETDEPS += $$PWD/fftw/liblibfftw3l-3.a
