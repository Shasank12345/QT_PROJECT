QT       += core gui
QT += sql
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_routine.cpp \
    adminstudent_edit.cpp \
    adminwindow.cpp \
    deleteroutine.cpp \
    editroutine.cpp \
    main.cpp \
    mainwindow.cpp \
    routinewindow.cpp \
    studentwindow.cpp \
    adminteacher_edit.cpp \
    takeattendance.cpp \
    teacherwindow.cpp \
    viewattendance.cpp \
    viewroutine.cpp

HEADERS += \
    add_routine.h \
    adminstudent_edit.h \
    adminwindow.h \
    deleteroutine.h \
    editroutine.h \
    mainwindow.h \
    routinewindow.h \
    studentwindow.h \
    adminteacher_edit.h \
    takeattendance.h \
    teacherwindow.h \
    viewattendance.h \
    viewroutine.h

FORMS += \
    add_routine.ui \
    adminstudent_edit.ui \
    adminwindow.ui \
    deleteroutine.ui \
    editroutine.ui \
    mainwindow.ui \
    routinewindow.ui \
    studentwindow.ui \
    adminteacher_edit.ui \
    takeattendance.ui \
    teacherwindow.ui \
    viewattendance.ui \
    viewroutine.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
