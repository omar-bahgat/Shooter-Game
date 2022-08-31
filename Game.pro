QT       += core gui \
         multimedia
         multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
QT += core gui multimedia
QT += multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enemy.cpp \
    Enemy2.cpp \
    Game.cpp \
    Projectile.cpp \
    Projectile2.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    room3.cpp

HEADERS += \
    Enemy.h \
    Enemy2.h \
    Game.h \
    Projectile.h \
    Projectile2.h \
    mainwindow.h \
    player.h \
    room3.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    background image.png \
    background image.png

RESOURCES += \
    resource2.qrc \
    resources.qrc
