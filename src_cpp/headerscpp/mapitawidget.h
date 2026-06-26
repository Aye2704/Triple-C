#ifndef MAPITAWIDGET_H
#define MAPITAWIDGET_H

//hago los includes para poder ocupar QT
#include<QWidget>
#include<QPainter>
#include<QKeyEvent>
#include"juego.hpp"
#include<QPaintEvent>
#include<QPixmap>


class maponW: public QWidget{
    Q_OBJECT
private:
    juego* motorJuego;
    int pixelsize;
    QPixmap fotoplayer;
    QPixmap fotoene;
    //QPixmap mapa;
    //QPixmap muro;

protected:
    void paintEvent(QPaintEvent* evento) override ;
    void keyPressEvent(QKeyEvent* teclita) override;
public:
    maponW(juego* j,QWidget* padre = nullptr);

    //Cambio: metodo para permitir que mainwindow ectualice el motor tras subir de nivel
    void setMotorJuego(juego* nuevoMotor);

signals:
    //Cambio: Señales que mainwindow escuchara
    void colisionEnemigoDetectada();
    void metaAlcanzada();
    void salirMenu(); //Nuevito para ya saben que
};

#endif // MAPITAWIDGET_H
