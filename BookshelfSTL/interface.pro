#-------------------------------------------------
#
# Project created by QtCreator 2015-09-29T23:57:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = interface
TEMPLATE = app


SOURCES += main.cpp\
        myinterface.cpp \
    dialog.cpp \
    dialog2.cpp \
    dialog3.cpp \
    book.cpp \
    bookshelf.cpp \
    dialoghelp.cpp \
    inheritancebook.cpp \
    formeditor.cpp \
    producer.cpp

HEADERS  += myinterface.h \
    book.h \
    bookshelf.h \
    dialog.h \
    dialog2.h \
    dialog3.h \
    dialoghelp.h \
    inheritancebook.h \
    formeditor.h \
    producer.h \
    bookaddable.h \
    updateable.h

FORMS    += myinterface.ui \
    dialog.ui \
    dialog2.ui \
    dialog3.ui \
    dialoghelp.ui \
    formeditor.ui

CONFIG += c++11
