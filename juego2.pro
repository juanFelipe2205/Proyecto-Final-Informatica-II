QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Enemigo.cpp \
    Juego.cpp \
    Jugador.cpp \
    Nivel.cpp \
    Nivel1.cpp \
    Nivel2.cpp \
    Nivel3.cpp \
    Obstaculo.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Enemigo.h \
    Juego.h \
    Jugador.h \
    Nivel.h \
    Nivel1.h \
    Nivel2.h \
    Nivel3.h \
    Obstaculo.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
