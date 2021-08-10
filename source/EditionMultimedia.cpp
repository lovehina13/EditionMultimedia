//==============================================================================
// Name        : EditionMultimedia.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
// Description : Main file of the EditionMultimedia project
//==============================================================================

#include "MainWindow.h"
#include <QApplication>

int main(int argc, char* argv[])
{
    QApplication application(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
