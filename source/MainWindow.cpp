//==============================================================================
// Name        : MainWindow.cpp
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (03/03/2020)
// Description : Source file of the MainWindow class
//==============================================================================

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "DocumentationWindow.h"
#include "MultimediaFile.h"
#include "Settings.h"
#include <QComboBox>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QSpinBox>
#include <QString>

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), _ui(new Ui::MainWindow)
{
    _ui->setupUi(this);

    updateLimits(0, 0);
    updateSettings();
}

MainWindow::~MainWindow()
{
    delete _ui;
}

void MainWindow::createNewData()
{
    const QString filePath = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier multimedia"), nullptr,
            QString::fromUtf8("Fichier multimedia (*.avi *.mkv *.mov *.mp4 *.mpeg *.mpg *.wmv)"));
    if (filePath.isEmpty())
        return;

    Settings settings;
    settings.setMultimediaFilePath(filePath);
    _data.setSettings(settings);

    MultimediaFile multimediaFile;
    multimediaFile.setFilePath(filePath);
    _data.setMultimediaFile(multimediaFile);

    updateLimits(0, _data.getMultimediaFile().getDuration() / 10);
    updateFrame(0);
    updateSettings();
}

void MainWindow::loadExistingData()
{
    const QString filePath = QFileDialog::getOpenFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), nullptr,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    _data.loadData(filePath);

    updateLimits(0, _data.getMultimediaFile().getDuration() / 10);
    updateFrame(0);
    updateSettings();
}

void MainWindow::saveCurrentData()
{
    const QString filePath = QFileDialog::getSaveFileName(this,
            QString::fromUtf8("Sélection d'un fichier d'édition multimedia"), nullptr,
            QString::fromUtf8("Fichier d'édition multimedia (*.csv)"));
    if (filePath.isEmpty())
        return;

    _data.saveData(filePath);
}

void MainWindow::processCurrentData()
{
    _data.encodeFile();
}

void MainWindow::updateFrame(const int& time)
{
    const QImage image = _data.getMultimediaFile().getFrame(time);
    _ui->labelFrame->setMinimumSize(image.width(), image.height());
    _ui->labelFrame->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::updateLimits(const int& min, const int& max)
{
    _ui->spinBoxFrameBegin->setMinimum(min);
    _ui->spinBoxFrameEnd->setMinimum(min);
    _ui->spinBoxFrameCurrent->setMinimum(min);

    _ui->spinBoxFrameBegin->setMaximum(max);
    _ui->spinBoxFrameEnd->setMaximum(max);
    _ui->spinBoxFrameCurrent->setMaximum(max);

    _ui->spinBoxFrameBegin->setValue(min);
    _ui->spinBoxFrameEnd->setValue(max);
    _ui->spinBoxFrameCurrent->setValue(min);
}

void MainWindow::updateSettings()
{
    const Settings& settings = _data.getSettings();
    _ui->comboBoxVideoMethod->setCurrentIndex(settings.getVideoMethod());
    _ui->comboBoxVideoSpeed->setCurrentIndex(settings.getVideoSpeed());
    _ui->comboBoxVideoQuality->setCurrentIndex(settings.getVideoQuality());
    _ui->spinBoxVideoBitRate->setValue(settings.getVideoBitRate());
    _ui->doubleSpinBoxVideoMaxSize->setValue(settings.getVideoMaxSize());
    _ui->doubleSpinBoxVideoFramesPerSecond->setValue(settings.getVideoFramesPerSecond());
    _ui->comboBoxAudioMethod->setCurrentIndex(settings.getAudioMethod());
    _ui->comboBoxAudioQuality->setCurrentIndex(settings.getAudioQuality());
    _ui->spinBoxAudioBitRate->setValue(settings.getAudioBitRate());

    const int& videoMethod = settings.getVideoMethod();
    if (videoMethod == Settings::VIDEO_METHOD_VARIABLE)
    {
        _ui->comboBoxVideoSpeed->setEnabled(true);
        _ui->comboBoxVideoQuality->setEnabled(true);
        _ui->spinBoxVideoBitRate->setEnabled(false);
        _ui->doubleSpinBoxVideoMaxSize->setEnabled(false);
    }
    else if (videoMethod == Settings::VIDEO_METHOD_CONSTANT)
    {
        _ui->comboBoxVideoSpeed->setEnabled(true);
        _ui->comboBoxVideoQuality->setEnabled(false);
        _ui->spinBoxVideoBitRate->setEnabled(true);
        _ui->doubleSpinBoxVideoMaxSize->setEnabled(false);
    }
    else if (videoMethod == Settings::VIDEO_METHOD_MAX_SIZE)
    {
        _ui->comboBoxVideoSpeed->setEnabled(false);
        _ui->comboBoxVideoQuality->setEnabled(false);
        _ui->spinBoxVideoBitRate->setEnabled(false);
        _ui->doubleSpinBoxVideoMaxSize->setEnabled(true);
    }

    const int& audioMethod = settings.getAudioMethod();
    if (audioMethod == Settings::AUDIO_METHOD_VARIABLE)
    {
        _ui->comboBoxAudioQuality->setEnabled(true);
        _ui->spinBoxAudioBitRate->setEnabled(false);
    }
    else if (audioMethod == Settings::AUDIO_METHOD_CONSTANT)
    {
        _ui->comboBoxAudioQuality->setEnabled(false);
        _ui->spinBoxAudioBitRate->setEnabled(true);
    }
}

void MainWindow::on_actionNew_triggered()
{
    createNewData();
}

void MainWindow::on_actionLoad_triggered()
{
    loadExistingData();
}

void MainWindow::on_actionSave_triggered()
{
    saveCurrentData();
}

void MainWindow::on_actionProcess_triggered()
{
    processCurrentData();
}

void MainWindow::on_actionQuit_triggered()
{
    close();
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
            QString::fromUtf8("EditionMultimedia - Version 1.0.0 (03/03/2020).\n"
                    "Réalisée par Alexis Foerster (alexis.foerster@gmail.com)."), QMessageBox::Ok,
            this);
    messageBox->exec();
}

void MainWindow::on_spinBoxFrameBegin_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setFromTime(_ui->spinBoxFrameBegin->value() * 10);
    _data.setSettings(settings);

    _ui->spinBoxFrameCurrent->setValue(_ui->spinBoxFrameBegin->value());
}

void MainWindow::on_spinBoxFrameCurrent_valueChanged()
{
    updateFrame(_ui->spinBoxFrameCurrent->value() * 10);
}

void MainWindow::on_spinBoxFrameEnd_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setToTime(_ui->spinBoxFrameEnd->value() * 10);
    _data.setSettings(settings);

    _ui->spinBoxFrameCurrent->setValue(_ui->spinBoxFrameEnd->value());
}

void MainWindow::on_comboBoxVideoMethod_currentIndexChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoMethod(_ui->comboBoxVideoMethod->currentIndex());
    _data.setSettings(settings);

    updateSettings();
}

void MainWindow::on_comboBoxVideoSpeed_currentIndexChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoSpeed(_ui->comboBoxVideoSpeed->currentIndex());
    _data.setSettings(settings);
}

void MainWindow::on_comboBoxVideoQuality_currentIndexChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoQuality(_ui->comboBoxVideoQuality->currentIndex());
    _data.setSettings(settings);
}

void MainWindow::on_spinBoxVideoBitRate_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoBitRate(_ui->spinBoxVideoBitRate->value());
    _data.setSettings(settings);
}

void MainWindow::on_doubleSpinBoxVideoMaxSize_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoMaxSize(_ui->doubleSpinBoxVideoMaxSize->value());
    _data.setSettings(settings);
}

void MainWindow::on_doubleSpinBoxVideoFramesPerSecond_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setVideoFramesPerSecond(_ui->doubleSpinBoxVideoFramesPerSecond->value());
    _data.setSettings(settings);
}

void MainWindow::on_comboBoxAudioMethod_currentIndexChanged()
{
    Settings settings = _data.getSettings();
    settings.setAudioMethod(_ui->comboBoxAudioMethod->currentIndex());
    _data.setSettings(settings);

    updateSettings();
}

void MainWindow::on_comboBoxAudioQuality_currentIndexChanged()
{
    Settings settings = _data.getSettings();
    settings.setAudioQuality(_ui->comboBoxAudioQuality->currentIndex());
    _data.setSettings(settings);
}

void MainWindow::on_spinBoxAudioBitRate_valueChanged()
{
    Settings settings = _data.getSettings();
    settings.setAudioBitRate(_ui->spinBoxAudioBitRate->value());
    _data.setSettings(settings);
}
