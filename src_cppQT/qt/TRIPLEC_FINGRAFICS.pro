QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    entidades.cpp \
    juego.cpp \
    main.cpp \
    mainwindow.cpp \
    mapa.cpp \
    mapitawidget.cpp \
    pantallasreal.cpp \
    pregBack.cpp

HEADERS += \
    entidades.hpp \
    juego.hpp \
    mainwindow.h \
    mapa.hpp \
    mapitawidget.h \
    preg.hpp \
    uireal.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
