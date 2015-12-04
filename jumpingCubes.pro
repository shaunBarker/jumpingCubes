#-------------------------------------------------
#
# Project created by QtCreator 2013-10-08T11:14:30
#
#-------------------------------------------------

QT       += core gui
QT       += widgets

TARGET = jumpingCubes
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    die.cpp \
    board.cpp \
    artificialintelligence.cpp

HEADERS  += mainwindow.h \
    die.h \
    board.h \
    artificialintelligence.h

FORMS    += mainwindow.ui

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
