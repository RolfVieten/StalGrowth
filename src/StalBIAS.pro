#-------------------------------------------------
#
# Project created by QtCreator 2015-04-16T19:19:30
#
#-------------------------------------------------

QT       += core gui positioning printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StalBIAS
TEMPLATE = app


SOURCES += main.cpp\
        stalbias.cpp \
        qcustomplot.cpp \
    graphviewer.cpp \
    dataitem.cpp \
    customseason.cpp

HEADERS  += stalbias.h \
            qcustomplot.h \
    graphviewer.h \
    dataitem.h \
    customseason.h

FORMS    += stalbias.ui \
    graphviewer.ui \
    customseason.ui
