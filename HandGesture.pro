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
INCLUDEPATH += /Users/liuguiyang/Documents/CodeProj/QtProj/HandGesture/source/video

SOURCES += source/main.cpp\
        source/video/handgesturedialog.cpp \
    source/gesture/GestrueInfo.cpp \
    source/gesture/AIGesture.cpp \
    source/utils/jsoncpp.cpp \
    source/utils/log.cpp \
    source/utils/utils.cpp \
    source/video/stronglabel.cpp \
    source/ui/threshold.cpp

HEADERS  += source/video/handgesturedialog.h \
    source/gesture/GestureStruct.h \
    source/gesture/GestrueInfo.h \
    source/gesture/AIGesture.h \
    source/utils/json/json-forwards.h \
    source/utils/json/json.h \
    source/utils/log.h \
    source/utils/utils.h \
    source/video/stronglabel.h \
    source/ui/threshold.h

FORMS    += source/video/handgesturedialog.ui \
    source/ui/threshold.ui

LIBS += -L/usr/local/Cellar/opencv/2.4.13/lib \
        -lopencv_core -lopencv_features2d \
        -lopencv_highgui -lopencv_imgproc \
        -lopencv_ml -lopencv_video -lopencv_contrib \
        -lopencv_ml -lopencv_objdetect

DISTFILES += \
    README.md \
    conf/configure.json

