#include "Komis_motoryzacyjny.h"
#include "ui_Komis_motoryzacyjny.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <sstream>

Komis_motoryzacyjny::Komis_motoryzacyjny(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::Komis_motoryzacyjny)
{
    ui->setupUi(this); 

    connect(ui->btnDodaj, &QPushButton::clicked, this, &Komis_motoryzacyjny::onDodajPojazdClicked);
    connect(ui->btnSprzedaj, &QPushButton::clicked, this, &Komis_motoryzacyjny::onSprzedajPojazdClicked);
    connect(ui->btnZapisz, &QPushButton::clicked, this, &Komis_motoryzacyjny::onZapiszClicked);
    connect(ui->btnWczytaj, &QPushButton::clicked, this, &Komis_motoryzacyjny::onWczytajClicked);
    connect(ui->btnSortuj, &QPushButton::clicked, this, &Komis_motoryzacyjny::onSortujClicked);
}


Komis_motoryzacyjny::~Komis_motoryzacyjny()
{
	delete ui;
}

void Komis_motoryzacyjny::onDodajPojazdClicked()
{

}

void Komis_motoryzacyjny::onSprzedajPojazdClicked() 
{
    bool ok;
    int index = QInputDialog::getInt(this, "Sprzedaj pojazd", "Indeks pojazdu:", 0, 0, komis.getPojazdy().size() - 1, 1, &ok);
    if (ok) 
    {
        komis.usunPojazd(index);
        aktualizujListePojazdow();
    }
}

void Komis_motoryzacyjny::onZapiszClicked() 
{
    QString nazwa = QFileDialog::getSaveFileName(this, "Zapisz do pliku");
    if (!nazwa.isEmpty()) 
    {
        komis.zapiszDoPliku(nazwa.toStdString());
    }
}

void Komis_motoryzacyjny::onWczytajClicked() 
{
    QString nazwa = QFileDialog::getOpenFileName(this, "Wczytaj z pliku");
    if (!nazwa.isEmpty()) 
    {
        komis.wczytajZPliku(nazwa.toStdString());
        aktualizujListePojazdow();
    }
}

void Komis_motoryzacyjny::onSortujClicked() {
    QStringList opcje = {
     "Cena rosnaco", "Cena malejaco",
     "Rok rosnaco", "Rok malejaco",
     "Przebieg rosnaco", "Przebieg malejaco"
    };

    bool ok;
    QString wybor = QInputDialog::getItem(this, "Sortowanie", "Wybierz:", opcje, 0, false, &ok);
    if (!ok)
    {
        return;
    }

    if (wybor == "Cena rosnaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getCena() < b->getCena(); });
    }
    else if (wybor == "Cena malejaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getCena() > b->getCena(); });
    }
    else if (wybor == "Rok rosnaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getRokProdukcji() < b->getRokProdukcji(); });
    }
    else if (wybor == "Rok malejaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getRokProdukcji() > b->getRokProdukcji(); });
    }
    else if (wybor == "Przebieg rosnaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getPrzebieg() < b->getPrzebieg(); });
    }
    else if (wybor == "Przebieg malejaco")
    {
        komis.sortuj([](Pojazd* a, Pojazd* b) { return a->getPrzebieg() > b->getPrzebieg(); });
    }

    aktualizujListePojazdow();
}

void Komis_motoryzacyjny::aktualizujListePojazdow() 
{
    ui->listWidget->clear();

    int i = 0;
    for (const auto& p : komis.getPojazdy()) 
    {
        std::ostringstream ss;
        ss << i << ": ";
        std::streambuf* oldCoutBuf = std::cout.rdbuf(); 
        std::ostringstream tempStream;
        std::cout.rdbuf(tempStream.rdbuf()); 
        p->wypisz();
        std::cout.rdbuf(oldCoutBuf); 

        ss << tempStream.str();
        ui->listWidget->addItem(QString::fromStdString(ss.str()));
        ++i;
    }
}
