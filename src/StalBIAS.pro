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
    customseason.cpp \
    plotselect.cpp \
    alglib/statistics.cpp \
    alglib/specialfunctions.cpp \
    alglib/solvers.cpp \
    alglib/optimization.cpp \
    alglib/linalg.cpp \
    alglib/interpolation.cpp \
    alglib/integration.cpp \
    alglib/fasttransforms.cpp \
    alglib/diffequations.cpp \
    alglib/dataanalysis.cpp \
    alglib/ap.cpp \
    alglib/alglibmisc.cpp \
    alglib/alglibinternal.cpp

HEADERS  += stalbias.h \
            qcustomplot.h \
    graphviewer.h \
    dataitem.h \
    customseason.h \
    plotselect.h \
    alglib/stdafx.h \
    alglib/statistics.h \
    alglib/specialfunctions.h \
    alglib/solvers.h \
    alglib/optimization.h \
    alglib/linalg.h \
    alglib/interpolation.h \
    alglib/integration.h \
    alglib/fasttransforms.h \
    alglib/diffequations.h \
    alglib/dataanalysis.h \
    alglib/ap.h \
    alglib/alglibmisc.h \
    alglib/alglibinternal.h

FORMS    += stalbias.ui \
    graphviewer.ui \
    customseason.ui \
    plotselect.ui
