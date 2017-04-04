#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T15:49:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TARGET = ping-pong
TEMPLATE = app


SOURCES += main.cpp \
    paddle.cpp \
    game.cpp \
    limit.cpp \
    ball.cpp

HEADERS  += \
    paddle.hpp \
    game.hpp \
    limit.hpp \
    ball.hpp

FORMS    +=
