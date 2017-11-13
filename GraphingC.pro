#QT += core
#QT .= gui
TARGET = sfmlTrial

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

include(deployment.pri)
qtcAddDeployment()

LIBS += -LC:\Qt\SFML-2.3.2\lib
LIBS += -LC:\Qt\SFML-2.3.2\bin

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system #ORDER MATTERS!
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += C:\Qt\SFML-2.3.2\include
DEPENDPATH += C:\Qt\SFML-2.3.2\include

CONFIG = c++11

HEADERS += \
    allconstants.h \
    bracket.h \
    number.h \
    operator.h \
    powerr.h \
    token.h \
    triangle.h \
    shuntingyard.h \
    game.h
