QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# Définition des chemins pour la nouvelle structure
SOURCES_DIR = $$PWD/src
UI_DIR = $$PWD/ui
RESOURCES_DIR = $$PWD/resources
COMPONENTS_DIR = $$PWD/components

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    $$SOURCES_DIR/main.cpp \
    $$SOURCES_DIR/widgets/widget.cpp

HEADERS += \
    $$SOURCES_DIR/widgets/widget.h

FORMS += \
    $$UI_DIR/widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    $$RESOURCES_DIR/icons.qrc

# Configuration pour la bibliothèque components
INCLUDEPATH += $$COMPONENTS_DIR
LIBS += -L$$PWD/./ -lcomponents

# Configuration de sortie
CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/build/debug
} else {
    DESTDIR = $$PWD/build/release
}

OBJECTS_DIR = $$DESTDIR/.obj
MOC_DIR = $$DESTDIR/.moc
RCC_DIR = $$DESTDIR/.rcc
UI_DIR = $$DESTDIR/.ui
