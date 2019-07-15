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
#include <QImage>
#include <QMessageBox>
#include <QPixmap>
#include <QString>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow)
{
    this->ui->setupUi(this);

    this->updateLimits(0, 0);
    this->updateSettings();
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

    Settings settings;
    settings.setMultimediaFilePath(filePath);
    this->data.setSettings(settings);

    MultimediaFile multimediaFile;
    multimediaFile.setFilePath(filePath);
    this->data.setMultimediaFile(multimediaFile);

    this->updateLimits(0, this->data.getMultimediaFile().getDuration() / 10);
    this->updateFrame(0);
    this->updateSettings();
}

void MainWindow::loadExistingData()
{
    const QString filePath = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), 0,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    this->data.loadData(filePath);

    this->updateLimits(0, this->data.getMultimediaFile().getDuration() / 10);
    this->updateFrame(0);
    this->updateSettings();
}

void MainWindow::saveCurrentData()
{
    const QString filePath = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), 0,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    this->data.saveData(filePath);
}

void MainWindow::processCurrentData()
{
    this->data.encodeFile();
}

void MainWindow::updateFrame(const int& time)
{
    const QImage image = this->data.getMultimediaFile().getFrame(time);
    this->ui->labelFrame->setMinimumSize(image.width(), image.height());
    this->ui->labelFrame->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::updateLimits(const int& min, const int& max)
{
    this->ui->spinBoxFrameBegin->setMinimum(min);
    this->ui->spinBoxFrameEnd->setMinimum(min);
    this->ui->spinBoxFrameCurrent->setMinimum(min);

    this->ui->spinBoxFrameBegin->setMaximum(max);
    this->ui->spinBoxFrameEnd->setMaximum(max);
    this->ui->spinBoxFrameCurrent->setMaximum(max);

    this->ui->spinBoxFrameBegin->setValue(min);
    this->ui->spinBoxFrameEnd->setValue(max);
    this->ui->spinBoxFrameCurrent->setValue(min);
}

void MainWindow::updateSettings()
{
    // TODO void MainWindow::updateSettings()
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
    this->ui->spinBoxFrameCurrent->setValue(this->ui->spinBoxFrameBegin->value());
}

void MainWindow::on_spinBoxFrameCurrent_valueChanged()
{
    this->updateFrame(this->ui->spinBoxFrameCurrent->value() * 10);
}

void MainWindow::on_spinBoxFrameEnd_valueChanged()
{
    this->ui->spinBoxFrameCurrent->setValue(this->ui->spinBoxFrameEnd->value());
}

void MainWindow::on_comboBoxVideoMethod_currentIndexChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoMethod(this->ui->comboBoxVideoMethod->currentIndex());
    this->data.setSettings(settings);

    this->updateSettings();
}

void MainWindow::on_comboBoxVideoQuality_currentIndexChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoQuality(this->ui->comboBoxVideoQuality->currentIndex());
    this->data.setSettings(settings);
}

void MainWindow::on_comboBoxVideoSpeed_currentIndexChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoSpeed(this->ui->comboBoxVideoSpeed->currentIndex());
    this->data.setSettings(settings);
}

void MainWindow::on_spinBoxVideoBitRate_valueChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoBitRate(this->ui->spinBoxVideoBitRate->value());
    this->data.setSettings(settings);
}

void MainWindow::on_doubleSpinBoxVideoMaxSize_valueChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoMaxSize(this->ui->doubleSpinBoxVideoMaxSize->value());
    this->data.setSettings(settings);
}

void MainWindow::on_doubleSpinBoxVideoFramesPerSecond_valueChanged()
{
    Settings settings = this->data.getSettings();
    settings.setVideoFramesPerSecond(this->ui->doubleSpinBoxVideoFramesPerSecond->value());
    this->data.setSettings(settings);
}

void MainWindow::on_comboBoxAudioMethod_currentIndexChanged()
{
    Settings settings = this->data.getSettings();
    settings.setAudioMethod(this->ui->comboBoxAudioMethod->currentIndex());
    this->data.setSettings(settings);

    this->updateSettings();
}

void MainWindow::on_spinBoxAudioBitRate_valueChanged()
{
    Settings settings = this->data.getSettings();
    settings.setAudioBitRate(this->ui->spinBoxAudioBitRate->value());
    this->data.setSettings(settings);
}
