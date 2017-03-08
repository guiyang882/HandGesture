cmake_minimum_required(VERSION 3.6)
project(HandGesture)

set(CMAKE_CXX_STANDARD 11)
#打开Qt的MOC功能和UI文件处理功能
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR on)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
#查找Qt的库
set(QT_HOME /usr/local/Cellar/qt5/5.8.0_1)
set(CMAKE_PREFIX_PATH ${QT_HOME})
find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5UiTools REQUIRED)

find_package(OpenCV 3 REQUIRED)

set(SOURCE_FILES
        source/gesture/AIGesture.cpp
        source/gesture/AIGesture.h
        source/gesture/GestrueInfo.cpp
        source/gesture/GestrueInfo.h
        source/gesture/GestureStruct.h
        source/ui/threshold.cpp
        source/ui/threshold.h
        source/ui/ui_threshold.h
        source/utils/json/json-forwards.h
        source/utils/json/json.h
        source/utils/jsoncpp.cpp
        source/utils/log.cpp
        source/utils/log.h
        source/utils/utils.cpp
        source/utils/utils.h
        source/video/handgesturedialog.cpp
        source/video/handgesturedialog.h
        source/video/ui_handgesturedialog.h
        source/video/stronglabel.cpp
        source/video/stronglabel.h
        source/main.cpp)

add_executable(HandGesture ${SOURCE_FILES})
target_link_libraries(HandGesture Qt5::Widgets Qt5::UiTools ${OpenCV_LIBS})