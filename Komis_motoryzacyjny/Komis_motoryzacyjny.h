#pragma once

#include <QtWidgets/QMainWindow>
#include "Komis.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Komis_motoryzacyjny; }
QT_END_NAMESPACE

class Komis_motoryzacyjny : public QMainWindow
{
    Q_OBJECT

public:
    Komis_motoryzacyjny(QWidget *parent = nullptr);
    ~Komis_motoryzacyjny();

private slots:
    void onDodajPojazdClicked();
    void onSprzedajPojazdClicked();
    void onZapiszClicked();
    void onWczytajClicked();
    void onSortujClicked();

private:
    Ui::Komis_motoryzacyjny* ui;
	Komis komis; 

	void aktualizujListePojazdow();
};
