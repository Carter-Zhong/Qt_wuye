#-------------------------------------------------
#
# Project created by QtCreator 2020-06-05T14:33:44
#
#-------------------------------------------------

QT       += core gui

QT       += axcontainer
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = test
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    comboboxdelegate.cpp \
        g_main.cpp \
    m_info.cpp \
    m_kaoqin.cpp \
    m_qingjia.cpp \
    w_main.cpp \
    w_info.cpp \
    w_jiaofei.cpp \
    w_chuqin.cpp \
    w_baoxiu.cpp \
    w_chewei.cpp \
    w_info_fang.cpp \
    w_info_jia.cpp \
    y_main.cpp \
    y_che.cpp \
    y_jiaofei.cpp \
    y_baoxiu.cpp \
    login.cpp \
    w_chewei_fen.cpp \
    m_system.cpp

HEADERS  += g_main.h \
    comboboxdelegate.h \
    m_info.h \
    m_kaoqin.h \
    connecction.h \
    m_qingjia.h \
    w_main.h \
    w_info.h \
    w_jiaofei.h \
    w_chuqin.h \
    w_baoxiu.h \
    w_chewei.h \
    w_info_fang.h \
    w_info_jia.h \
    y_main.h \
    y_che.h \
    y_jiaofei.h \
    y_baoxiu.h \
    login.h \
    w_chewei_fen.h \
    m_system.h

FORMS    += g_main.ui \
    m_info.ui \
    m_kaoqin.ui \
    m_qingjia.ui \
    w_main.ui \
    w_info.ui \
    w_jiaofei.ui \
    w_chuqin.ui \
    w_baoxiu.ui \
    w_chewei.ui \
    w_info_fang.ui \
    w_info_jia.ui \
    y_main.ui \
    y_che.ui \
    y_jiaofei.ui \
    y_baoxiu.ui \
    login.ui \
    w_chewei_fen.ui \
    m_system.ui

DISTFILES +=

RESOURCES += \
    resource.qrc

RC_ICONS = bitbug.ico
