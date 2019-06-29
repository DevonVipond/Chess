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
    models/chessboard.cpp \
    pieces/piece.cpp \
    pieces/pawn.cpp \
    coordinate.cpp \
    pieces/chessmoves.cpp \
    pieces/knight.cpp \
    pieces/rook.cpp \
    pieces/bishop.cpp \
    view/square.cpp \
    pieces/movevalidator.cpp \
    models/gamestate.cpp \
    main.cpp \
    pieces/king.cpp \
    pieces/queen.cpp \
    view/mainwindow.cpp \
    ai/aimovedeterminator.cpp

HEADERS += \
    models/chessboard.h \
    #models/chessgame.h \
    pieces/piece.h \
    pieces/pawn.h \
    pieces/chessmoves.h \
    pieces/knight.h \
    view/square.h \
    pieces/bishop.h \
    coordinate.h \
    view/rook.h \
    translations.h \
    pieces/movevalidator.h \
    models/gamestate.h \
    view/king.h \
    view/queen.h \
    view/mainwindow.h \
    ai/aimovedeterminator.h

FORMS += \
        view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
