cmake_minimum_required(VERSION 2.6)

project(EditionMultimedia)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS interfaces)

find_package(Qt4 4.8.7 REQUIRED QtCore QtGui)

qt4_wrap_cpp(MOC_FILES
    include/DocumentationWindow.h
    include/MainWindow.h)

add_executable(EditionMultimedia
    source/Data.cpp
    source/DocumentationWindow.cpp
    source/EditionMultimedia.cpp
    source/MainWindow.cpp
    source/MultimediaFile.cpp
    source/Settings.cpp
    source/Tools.cpp
    interfaces/DocumentationWindow.ui
    interfaces/MainWindow.ui
    resources/Ressources.qrc
    ${MOC_FILES})

target_link_libraries(EditionMultimedia PUBLIC Qt4::QtCore Qt4::QtGui)

target_include_directories(EditionMultimedia PUBLIC include)

install(TARGETS EditionMultimedia DESTINATION bin)
