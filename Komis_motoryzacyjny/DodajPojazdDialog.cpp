#include "DodajPojazdDialog.h"
#include "ui_DodajPojazdDialog.h"
#include <QString>
#include <QMessageBox>
#include "SamochodOsobowy.h"
#include "SamochodDostawczy.h"
#include "Motocykl.h"

DodajPojazdDialog::DodajPojazdDialog(QWidget* parent) :
    QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);

    ui->comboBoxTyp->addItem("Samochod osobowy");
    ui->comboBoxTyp->addItem("Motocykl");
    ui->comboBoxTyp->addItem("Samochod dostawczy");

    ustawWidocznoscPol(ui->comboBoxTyp->currentText());

    connect(ui->comboBoxTyp, &QComboBox::currentTextChanged, this, &DodajPojazdDialog::ustawWidocznoscPol);
}

DodajPojazdDialog::~DodajPojazdDialog()
{
    delete ui;
}

void DodajPojazdDialog::ustawWidocznoscPol(const QString& typ)
{
    ui->labelPojemnosc->setVisible(true);
    ui->lineEditPojemnosc->setVisible(true);

    ui->labelPrzebieg->setVisible(true);
    ui->lineEditPrzebieg->setVisible(true);

    ui->labelRok->setVisible(true);
    ui->lineEditRok->setVisible(true);

    ui->labelCena->setVisible(true);
    ui->lineEditCena->setVisible(true);

    ui->labelDrzwi->setVisible(typ == "Samochod osobowy");
    ui->lineEditDrzwi->setVisible(typ == "Samochod osobowy");

    ui->labelLadownosc->setVisible(typ == "Samochod dostawczy");
    ui->lineEditLadownosc->setVisible(typ == "Samochod dostawczy");

    ui->checkBoxKufry->setVisible(typ == "Motocykl");
    ui->labelKufry->setVisible(typ == "Motocykl");
}


Pojazd* DodajPojazdDialog::utworzPojazd()
{
    bool ok;
    double pojemnosc = ui->lineEditPojemnosc->text().toDouble(&ok);
    if (!ok) 
    {
        QMessageBox::warning(this, "Blad", "Niepoprawna pojemnosc silnika");
        return nullptr;
    }

    int przebieg = ui->lineEditPrzebieg->text().toInt(&ok);
    if (!ok) 
    {
        QMessageBox::warning(this, "Blad", "Niepoprawny przebieg");
        return nullptr;
    }

    int rok = ui->lineEditRok->text().toInt(&ok);
    if (!ok) 
    {
        QMessageBox::warning(this, "Blad", "Niepoprawny rok produkcji");
        return nullptr;
    }

    double cena = ui->lineEditCena->text().toDouble(&ok);
    if (!ok) 
    {
        QMessageBox::warning(this, "Blad", "Niepoprawna cena");
        return nullptr;
    }

    QString typ = ui->comboBoxTyp->currentText();

    if (typ == "Samochod osobowy") {
        int drzwi = ui->lineEditDrzwi->text().toInt(&ok);
        if (!ok) 
        {
            QMessageBox::warning(this, "Blad", "Niepoprawna liczba drzwi");
            return nullptr;
        }
        return new SamochodOsobowy(pojemnosc, przebieg, rok, cena, drzwi);
    }
    else if (typ == "Samochod dostawczy") {
        double ladownosc = ui->lineEditLadownosc->text().toDouble(&ok);
        if (!ok) 
        {
            QMessageBox::warning(this, "Blad", "Niepoprawna ladownosc");
            return nullptr;
        }
        return new SamochodDostawczy(pojemnosc, przebieg, rok, cena, ladownosc);
    }
    else if (typ == "Motocykl") 
    {
        bool kufry = ui->checkBoxKufry->isChecked();
        return new Motocykl(pojemnosc, przebieg, rok, cena, kufry);
    }

    QMessageBox::warning(this, "Blad", "Nieznany typ pojazdu");
    return nullptr;
}