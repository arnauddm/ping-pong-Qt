#-------------------------------------------------
#
# Project created by QtCreator 2016-10-28T15:49:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ping-pong
TEMPLATE = app


SOURCES += main.cpp \
    ball.cpp \
    paddle.cpp \
    game.cpp \
    limit.cpp

HEADERS  += \
    ball.hpp \
    paddle.hpp \
    game.hpp \
    limit.hpp

FORMS    +=
