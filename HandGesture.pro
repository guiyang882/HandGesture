#-------------------------------------------------
#
# Project created by QtCreator 2013-05-25T11:16:11
#
#-------------------------------------------------

QT       += core gui

CONFIG += warn_off

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = HandGesture
TEMPLATE = app

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.13/include

SOURCES += source/main.cpp\
        source/handgesturedialog.cpp \
    source/gesture/GestrueInfo.cpp \
    source/gesture/AIGesture.cpp

HEADERS  += source/handgesturedialog.h \
    source/gesture/GestureStruct.h \
    source/gesture/GestrueInfo.h \
    source/gesture/AIGesture.h

FORMS    += source/handgesturedialog.ui

LIBS += -L/usr/local/Cellar/opencv/2.4.13/lib \
        -lopencv_core -lopencv_features2d \
        -lopencv_highgui -lopencv_imgproc \
        -lopencv_ml -lopencv_video -lopencv_contrib \
        -lopencv_ml -lopencv_objdetect

DISTFILES += \
    README.md

