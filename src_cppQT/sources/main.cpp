#include "mainwindow.h"
#include<mapitawidget.h>
#include <QApplication>
#include <ctime>
#include <cstdlib>
#include "juego.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand(time(NULL));

    juego motorJuego;
    maponW ventanamapa(&motorJuego);

    ventanamapa.resize(600, 600);
    ventanamapa.show();
    return a.exec();
}
