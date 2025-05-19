#include "Komis_motoryzacyjny.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Komis_motoryzacyjny w;
    w.show();
    return a.exec();
}
