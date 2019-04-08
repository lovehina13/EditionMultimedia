//==============================================================================
// Name        : MainWindow.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Source file of the MainWindow class
//==============================================================================

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DocumentationWindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QString>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete this->ui;
}

void MainWindow::createNewData()
{
    const QString filePath = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier multimedia"), 0,
            QString::fromUtf8("Fichier multimedia (*.avi *.mkv *.mov *.mp4 *.mpeg *.mpg *.wmv)"));
    if (filePath.isEmpty())
        return;

    // TODO void MainWindow::createNewData()
}

void MainWindow::loadExistingData()
{
    const QString filePath = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), 0,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    // TODO void MainWindow::loadExistingData()
}

void MainWindow::saveCurrentData()
{
    const QString filePath = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), 0,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    // TODO void MainWindow::saveCurrentData()
}

void MainWindow::processCurrentData()
{
    // TODO void MainWindow::processCurrentData()
}

void MainWindow::on_actionNew_triggered()
{
    this->createNewData();
}

void MainWindow::on_actionLoad_triggered()
{
    this->loadExistingData();
}

void MainWindow::on_actionSave_triggered()
{
    this->saveCurrentData();
}

void MainWindow::on_actionProcess_triggered()
{
    this->processCurrentData();
}

void MainWindow::on_actionQuit_triggered()
{
    this->close();
}

void MainWindow::on_actionDocumentation_triggered()
{
    DocumentationWindow* documentationWindow = new DocumentationWindow(this);
    documentationWindow->exec();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox* messageBox = new QMessageBox(QMessageBox::Information,
            QString::fromUtf8("EditionMultimedia"),
            QString::fromUtf8("EditionMultimedia - Version 1.0.0 (05/04/2019).\n"
                    "Réalisée par Alexis Foerster (alexis.foerster@gmail.com)."), QMessageBox::Ok,
            this);
    messageBox->exec();
}

void MainWindow::on_spinBoxFrameBegin_valueChanged()
{
    // TODO void MainWindow::on_spinBoxFrameBegin_valueChanged()
}

void MainWindow::on_spinBoxFrameCurrent_valueChanged()
{
    // TODO void MainWindow::on_spinBoxFrameCurrent_valueChanged()
}

void MainWindow::on_spinBoxFrameEnd_valueChanged()
{
    // TODO void MainWindow::on_spinBoxFrameEnd_valueChanged()
}

void MainWindow::on_comboBoxVideoMethod_currentIndexChanged()
{
    // TODO void MainWindow::on_comboBoxVideoMethod_currentIndexChanged()
}

void MainWindow::on_comboBoxVideoQuality_currentIndexChanged()
{
    // TODO void MainWindow::on_comboBoxVideoQuality_currentIndexChanged()
}

void MainWindow::on_comboBoxVideoSpeed_currentIndexChanged()
{
    // TODO void MainWindow::on_comboBoxVideoSpeed_currentIndexChanged()
}

void MainWindow::on_spinBoxVideoBitRate_valueChanged()
{
    // TODO void MainWindow::on_spinBoxVideoBitRate_valueChanged()
}

void MainWindow::on_doubleSpinBoxVideoMaxSize_valueChanged()
{
    // TODO void MainWindow::on_doubleSpinBoxVideoMaxSize_valueChanged()
}

void MainWindow::on_doubleSpinBoxVideoFramesPerSecond_valueChanged()
{
    // TODO void MainWindow::on_doubleSpinBoxVideoFramesPerSecond_valueChanged()
}

void MainWindow::on_comboBoxAudioMethod_currentIndexChanged()
{
    // TODO void MainWindow::on_comboBoxAudioMethod_currentIndexChanged()
}

void MainWindow::on_spinBoxAudioBitRate_valueChanged()
{
    // TODO void MainWindow::on_spinBoxAudioBitRate_valueChanged()
}
