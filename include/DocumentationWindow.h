//==============================================================================
// Name        : DocumentationWindow.h
// Author      : Alexis Foerster (alexis.foerster@gmail.com)
// Version     : 1.1.0 (10/08/2021)
// Description : Header file of the DocumentationWindow class
//==============================================================================

#ifndef DOCUMENTATIONWINDOW_H
#define DOCUMENTATIONWINDOW_H

#include <QDialog>
#include <QWidget>

namespace Ui
{
class DocumentationWindow;
}

class DocumentationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DocumentationWindow(QWidget* parent = nullptr);
    virtual ~DocumentationWindow() override;

private:
    Ui::DocumentationWindow* _ui { nullptr };
};

#endif /* DOCUMENTATIONWINDOW_H */
