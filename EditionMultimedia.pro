#===============================================================================
# Name        : EditionMultimedia.pro
# Author      : Alexis Foerster (alexis.foerster@gmail.com)
# Version     : 1.0.0 (05/04/2019)
# Description : Qt project file of the EditionMultimedia project
#===============================================================================

TEMPLATE = app
TARGET = EditionMultimedia
DEPENDPATH += . include source
INCLUDEPATH += . include
OBJECTS_DIR = objects
MOC_DIR = objects
RCC_DIR = objects
UI_DIR = objects

HEADERS += include/Data.h \
           include/DocumentationWindow.h \
           include/MainWindow.h \
           include/MultimediaFile.h \
           include/Settings.h \
           include/Tools.h
SOURCES += source/EditionMultimedia.cpp \
           source/Data.cpp \
           source/DocumentationWindow.cpp \
           source/MainWindow.cpp \
           source/MultimediaFile.cpp \
           source/Settings.cpp \
           source/Tools.cpp
FORMS += interfaces/DocumentationWindow.ui \
         interfaces/MainWindow.ui
RESOURCES += ressources/Ressources.qrc

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra
# QMAKE_CXXFLAGS += -std=c++11 -pedantic -pedantic-errors -Wall -Wextra -Wconversion -Wsign-conversion -Wold-style-cast -Wunused-parameter -Werror
