#-------------------------------------------------
#
# Project created by QtCreator 2015-08-10T16:08:24
#
#-------------------------------------------------

QT       += core
QT       += gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DataBase
TEMPLATE = app


SOURCES += main.cpp\
    appendincomewindow.cpp \
    appendspendingwindow.cpp \
    database.cpp \
    mainwindow.cpp \

HEADERS  += mainwindow.h \
    appendincomewindow.h \
    appendspendingwindow.h \
    database.h \

FORMS    += mainwindow.ui \
    appendincomewindow.ui \
    appendspendingwindow.ui \
