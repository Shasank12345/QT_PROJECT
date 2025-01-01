QT       += core gui
QT += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminstudent_edit.cpp \
    adminwindow.cpp \
    crwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    routinewindow.cpp \
    studentwindow.cpp \
    teacherwindow.cpp

HEADERS += \
    adminstudent_edit.h \
    adminwindow.h \
    crwindow.h \
    mainwindow.h \
    routinewindow.h \
    studentwindow.h \
    teacherwindow.h

FORMS += \
    adminstudent_edit.ui \
    adminwindow.ui \
    crwindow.ui \
    mainwindow.ui \
    routinewindow.ui \
    studentwindow.ui \
    teacherwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
