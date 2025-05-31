#pragma once

#include <QDialog>
#include "Pojazd.h"

namespace Ui 
{
    class Dialog;
}

class DodajPojazdDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DodajPojazdDialog(QWidget* parent = nullptr);
    ~DodajPojazdDialog();

    Pojazd* utworzPojazd();

private:
    Ui::Dialog* ui;

    void ustawWidocznoscPol(const QString& typ);
};

