#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Komis_motoryzacyjny.h"

class Komis_motoryzacyjny : public QMainWindow
{
    Q_OBJECT

public:
    Komis_motoryzacyjny(QWidget *parent = nullptr);
    ~Komis_motoryzacyjny();

private:
    Ui::Komis_motoryzacyjnyClass ui;
};
