#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T16:08:24
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DataBase
TEMPLATE = app


SOURCES += main.cpp\
    appendincomewindow.cpp \
    appendspendingwindow.cpp \
    balancechartwindow.cpp \
    categoryreportwindow.cpp \
    database.cpp \
    mainwindow.cpp \
    periodreportwindow.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    appendincomewindow.h \
    appendspendingwindow.h \
    balancechartwindow.h \
    categoryreportwindow.h \
    database.h \
    periodreportwindow.h \
    qcustomplot.h

FORMS    += mainwindow.ui \
    appendincomewindow.ui \
    appendspendingwindow.ui \
    balancechartwindow.ui \
    categoryreportwindow.ui \
    periodreportwindow.ui
