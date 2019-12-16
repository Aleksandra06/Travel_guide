#-------------------------------------------------
#
# Project created by QtCreator 2019-12-15T18:20:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Kurse
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


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    first_sub_menu_widget.cpp \
    second_sub_menu_widget.cpp \
    third_sub_menu_widget.cpp \
    fourth_sub_menu_widget.cpp \
    fifth_sub_menu_widget.cpp \
    second_main_menu_widget.cpp \
    third_main_menu_widget.cpp \
    fourth_main_menu_widget.cpp \
    fifth_main_menu_widget.cpp

HEADERS += \
        mainwindow.h \
    first_sub_menu_widget.h \
    second_sub_menu_widget.h \
    third_sub_menu_widget.h \
    fourth_sub_menu_widget.h \
    fifth_sub_menu_widget.h \
    second_main_menu_widget.h \
    third_main_menu_widget.h \
    fourth_main_menu_widget.h \
    fifth_main_menu_widget.h

FORMS += \
        mainwindow.ui \
    first_sub_menu_widget.ui \
    second_sub_menu_widget.ui \
    third_sub_menu_widget.ui \
    fourth_sub_menu_widget.ui \
    fifth_sub_menu_widget.ui \
    second_main_menu_widget.ui \
    third_main_menu_widget.ui \
    fourth_main_menu_widget.ui \
    fifth_main_menu_widget.ui
