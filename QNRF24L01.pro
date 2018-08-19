QT += core
QT -= gui

CONFIG += c++11

TARGET = QNRF24L01
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    3rdparty/utility/RPi/spi.cpp \
    3rdparty/RF24.cpp \
    3rdparty/utility/RPi/bcm2835.c \
    3rdparty/utility/RPi/interrupt.cpp \
    qnrf24l01.cpp \
    example.cpp

HEADERS += \
    3rdparty/utility/RPi/bcm2835.h \
    3rdparty/utility/RPi/includes.h \
    3rdparty/utility/RPi/interrupt.h \
    3rdparty/utility/RPi/RF24_arch_config.h \
    3rdparty/utility/RPi/spi.h \
    3rdparty/utility/includes.h \
    3rdparty/nRF24L01.h \
    3rdparty/printf.h \
    3rdparty/RF24.h \
    3rdparty/RF24_config.h \
    qnrf24l01.h \
    example.h


target.path = /home/pi/
INSTALLS += target


