#-------------------------------------------------
#
# Project created by QtCreator 2016-05-02T19:05:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = kr_integ
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    multiple_integral.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    multiple_integral.h \
    qcustomplot.h

FORMS    += mainwindow.ui
