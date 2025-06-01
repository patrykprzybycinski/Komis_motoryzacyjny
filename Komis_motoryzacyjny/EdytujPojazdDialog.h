#pragma once

#include <QDialog>
#include "Pojazd.h"

namespace Ui
{
    class EdytujPojazdDialog;
}

class EdytujPojazdDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EdytujPojazdDialog(Pojazd* pojazd, QWidget* parent = nullptr);
    ~EdytujPojazdDialog();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::EdytujPojazdDialog* ui;
    Pojazd* pojazd;

    void ustawWidocznoscPol();        
    void wypelnijPola();              
    void zapiszZmiany();              
};

