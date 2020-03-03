//==============================================================================
// Name        : MainWindow.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.0.0 (05/04/2019)
// Description : Header file of the MainWindow class
//==============================================================================

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Data.h"
#include <QMainWindow>
#include <QWidget>

namespace Ui
{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    virtual ~MainWindow();

protected:
    void createNewData();
    void loadExistingData();
    void saveCurrentData();
    void processCurrentData();
    void updateFrame(const int& time);
    void updateLimits(const int& min, const int& max);
    void updateSettings();

protected slots:
    void on_actionNew_triggered();
    void on_actionLoad_triggered();
    void on_actionSave_triggered();
    void on_actionProcess_triggered();
    void on_actionQuit_triggered();
    void on_actionDocumentation_triggered();
    void on_actionAbout_triggered();
    void on_spinBoxFrameBegin_valueChanged();
    void on_spinBoxFrameCurrent_valueChanged();
    void on_spinBoxFrameEnd_valueChanged();
    void on_comboBoxVideoMethod_currentIndexChanged();
    void on_comboBoxVideoSpeed_currentIndexChanged();
    void on_comboBoxVideoQuality_currentIndexChanged();
    void on_spinBoxVideoBitRate_valueChanged();
    void on_doubleSpinBoxVideoMaxSize_valueChanged();
    void on_doubleSpinBoxVideoFramesPerSecond_valueChanged();
    void on_comboBoxAudioMethod_currentIndexChanged();
    void on_comboBoxAudioQuality_currentIndexChanged();
    void on_spinBoxAudioBitRate_valueChanged();

private:
    Ui::MainWindow* ui;
    Data data;
};

#endif /* MAINWINDOW_H */
