#include "EdytujPojazdDialog.h"
#include "ui_EdytujPojazdDialog.h"
#include "SamochodOsobowy.h"
#include "Motocykl.h"
#include "SamochodDostawczy.h"
#include <QString>
#include <QDate>
#include <QDebug>

EdytujPojazdDialog::EdytujPojazdDialog(Pojazd* pojazd, QWidget* parent)
    : QDialog(parent)
    , ui(new Ui::EdytujPojazdDialog)
    , pojazd(pojazd)
{
    ui->setupUi(this);

    ui->cenaSpin->setRange(0, 1000000);
    ui->cenaSpin->setSingleStep(1000);
    ui->pojemnoscSpin->setRange(0, 10000);
    ui->przebiegSpin->setRange(0, 1000000);
    ui->rokSpin->setRange(1900, QDate::currentDate().year());
    ui->drzwiSpin->setRange(1, 5);
    ui->ladownoscSpin->setRange(0, 100000);

    ustawWidocznoscPol();
    wypelnijPola();

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &EdytujPojazdDialog::on_buttonBox_accepted);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &EdytujPojazdDialog::on_buttonBox_rejected);
}

EdytujPojazdDialog::~EdytujPojazdDialog()
{
    delete ui;
}

void EdytujPojazdDialog::on_buttonBox_accepted()
{
    zapiszZmiany();
    accept();
}

void EdytujPojazdDialog::on_buttonBox_rejected()
{
    reject();
}

void EdytujPojazdDialog::ustawWidocznoscPol()
{
    ui->drzwiLabel->setVisible(false);
    ui->drzwiSpin->setVisible(false);

    ui->kuferCheckBox->setVisible(false);
    ui->kuferLabel->setVisible(false);

    ui->ladownoscLabel->setVisible(false);
    ui->ladownoscSpin->setVisible(false);

    if (dynamic_cast<SamochodOsobowy*>(pojazd)) 
    {
        ui->drzwiLabel->setVisible(true);
        ui->drzwiSpin->setVisible(true);
    }
    else if (dynamic_cast<Motocykl*>(pojazd)) 
    {
        ui->kuferLabel->setVisible(true);
        ui->kuferCheckBox->setVisible(true);
    }
    else if (dynamic_cast<SamochodDostawczy*>(pojazd)) 
    {
        ui->ladownoscLabel->setVisible(true);
        ui->ladownoscSpin->setVisible(true);
    }
}

void EdytujPojazdDialog::wypelnijPola()
{
    if (!pojazd) 
    {
        qWarning() << "B³¹d: wskaŸnik pojazdu jest pusty!";
        return;
    }

    ui->pojemnoscSpin->setValue(static_cast<int>(pojazd->getPojemnoscSilnika()));
    ui->przebiegSpin->setValue(pojazd->getPrzebieg());
    ui->rokSpin->setValue(pojazd->getRokProdukcji());
    ui->cenaSpin->setValue(static_cast<int>(pojazd->getCena()));

    if (auto osobowy = dynamic_cast<SamochodOsobowy*>(pojazd)) 
    {
        ui->drzwiSpin->setValue(osobowy->getLiczbaDrzwi());
    }
    else if (auto motocykl = dynamic_cast<Motocykl*>(pojazd)) 
    {
        ui->kuferCheckBox->setChecked(motocykl->czyMaKufry());
    }
    else if (auto ciezarowy = dynamic_cast<SamochodDostawczy*>(pojazd)) 
    {
        ui->ladownoscSpin->setValue(static_cast<int>(ciezarowy->getLadownosc()));
    }
}

void EdytujPojazdDialog::zapiszZmiany()
{
    pojazd->setPojemnoscSilnika(ui->pojemnoscSpin->value());
    pojazd->setPrzebieg(ui->przebiegSpin->value());
    pojazd->setRokProdukcji(ui->rokSpin->value());
    pojazd->setCena(ui->cenaSpin->value());

    if (auto osobowy = dynamic_cast<SamochodOsobowy*>(pojazd)) 
    {
        osobowy->setLiczbaDrzwi(ui->drzwiSpin->value());
    }
    else if (auto motocykl = dynamic_cast<Motocykl*>(pojazd)) 
    {
        motocykl->setKufry(ui->kuferCheckBox->isChecked());
    }
    else if (auto ciezarowy = dynamic_cast<SamochodDostawczy*>(pojazd)) 
    {
        ciezarowy->setLadownosc(ui->ladownoscSpin->value());
    }
}
