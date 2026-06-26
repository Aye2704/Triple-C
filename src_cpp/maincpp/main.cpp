#include "mainwindow.h"
#include <QApplication>
#include <ctime>
#include <cstdlib>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    //inicar similla aleatoria para movimientos autonomo de entidades
    srand(static_cast<unsigned>(time(NULL)));

    MainWindow w;
    w.setWindowTitle("Triple-C: locura absoluta");
    w.resize(800, 600);
    w.show();

    return a.exec();
}