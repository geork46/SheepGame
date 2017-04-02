#-------------------------------------------------
#
# Project created by QtCreator 2017-04-01T20:41:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SheepGame
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    GameField.cpp \
    AbstractSheep.cpp \
    SheepTypeA.cpp \
    StartForm.cpp

HEADERS  += widget.h \
    GameField.h \
    AbstractSheep.h \
    SheepTypeA.h \
    StartForm.h

FORMS    += widget.ui \
    StartForm.ui

RESOURCES += \
    resource.qrc
