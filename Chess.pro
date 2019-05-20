#-------------------------------------------------
#
# Project created by QtCreator 2019-01-01T11:48:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Chess
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
CONFIG += console

SOURCES += \
        mainwindow.cpp \
    chessboard.cpp \
    chessgame.cpp \
    piece.cpp \
    pawn.cpp \
    coordinate.cpp \
    chessmoves.cpp \
    knight.cpp \
    rook.cpp \
    bishop.cpp \
    view/square.cpp \
    view/chessview.cpp

HEADERS += \
        mainwindow.h \
    chessboard.h \
    chessgame.h \
    piece.h \
    pawn.h \
    coordinate.h \
    chessmoves.h \
    knight.h \
    rook.h \
    bishop.h \
    view/square.h \
    view/chessview.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

