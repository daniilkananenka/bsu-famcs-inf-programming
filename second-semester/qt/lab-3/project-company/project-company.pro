QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    misseddeadlineperformersdialog.cpp \
    performertasksdialog.cpp \
    projectitem.cpp \
    projectperformersdialog.cpp \
    projectservice.cpp \
    supervisorprojectsdialog.cpp

HEADERS += \
    mainwindow.h \
    misseddeadlineperformersdialog.h \
    performertasksdialog.h \
    projectitem.h \
    projectperformersdialog.h \
    projectservice.h \
    supervisorprojectsdialog.h

FORMS += \
    mainwindow.ui \
    misseddeadlineperformersdialog.ui \
    performertasksdialog.ui \
    projectperformersdialog.ui \
    supervisorprojectsdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    output
