#include "mapitawidget.h"


//este es el constructor de mi objeto aqui le pongo setfocuspolicy para indicarle a la ventana
//q este bien despierta pa que reciba todas las teclas que el jugador aprete
maponW::maponW(juego* j,QWidget* padre)
    :QWidget(padre),motorJuego(j),pixelsize(32)
{
    setFocusPolicy(Qt::StrongFocus);

    fotoplayer.load("C:/gitchulini/RUTA/fototriplec/wekeche");
    fotoene.load("C:/gitchulini/RUTA/fototriplec/nicki");

}

void maponW::setMotorJuego(juego* nuevoMotor) {
    motorJuego = nuevoMotor;
    update();
}

void maponW::paintEvent(QPaintEvent* evento){
    QPainter painter(this);


    //parto ocupando todos los metodos nuevos que defini pa sacar la info
    //y similar a la funcion dibujar anterior con 2 ciclos for para recorrer todo mi mapa
    //y con logica de ifs y else ifs para saber si dibujar al jugador , enemigo, muros o mapa
    int dimensionnow=motorJuego->obtdimensionmapa();
    /*int posxjug=motorJuego->obtjugX();
    int posyjug=motorJuego->obtjugY();
    int posxene=motorJuego->obteneX();
    int posyene=motorJuego->obteneY();*/ // predon pot los cambios ale

    for(int i=0;i<dimensionnow;i++){
        for(int j=0;j<dimensionnow;j++){
            QRect rect(j*pixelsize,i*pixelsize,pixelsize,pixelsize);
            char casilla = motorJuego->obtcasillamapa(j, i);

            if(casilla == '#'){
                painter.setBrush(QBrush(QColor(44,62,80))); //color azul oscuro para muros
                painter.setPen(Qt::NoPen);
                painter.drawRect(rect);


            } else {
                painter.setBrush(QBrush(QColor(236, 240, 241))); //Fondo del mapa 
                painter.setPen(QPen(QColor(218, 223, 230), 1));
                painter.drawRect(rect);
            }
        }
    }
    //Dibujar meta
    QRect rectMeta(motorJuego->obtmetaX() * pixelsize, motorJuego->obtmetaY() * pixelsize, pixelsize, pixelsize);
    painter.setBrush(QBrush(QColor(46, 204, 113))); // Color verde para la meta
    painter.drawRect(rectMeta);

    //Dibujar enemigo
    if (!motorJuego->isEnemigoDerrotado()) {
        QRect rectEne(motorJuego->obteneX() * pixelsize, motorJuego->obteneY() * pixelsize, pixelsize, pixelsize);
        if (!fotoene.isNull()) {
            painter.drawPixmap(rectEne, fotoene);
        } else {
            painter.setBrush(QBrush(QColor(231, 76, 60))); //Alternativo
            painter.drawEllipse(rectEne);
        }
    }

    //Dibujar jugador
    QRect rectJug(motorJuego->obtjugX() * pixelsize, motorJuego->obtjugY() * pixelsize, pixelsize, pixelsize);
    if (!fotoplayer.isNull()) {
        painter.drawPixmap(rectJug, fotoplayer);
    } else {
        painter.setBrush(QBrush(QColor(52, 152, 219))); //Alternativo
        painter.drawEllipse(rectJug);
    }
}

void maponW::keyPressEvent(QKeyEvent* teclita) {
    if (!motorJuego) return;
    char teclapresionada=' ';

    //ocupo mi puntero y la funcion key para detectar si se apreto una tecla y si fue alguna de WASD
    //analogo con lo que se hizo anteriormente en C++
    //si se apreta Q se cerrara mi ventana por eso el this con el close
    //ya arregle varias veces la logica y el movimiento funciona bien pero me siguen saliendo
    //esos warnings :(

        if(teclita->key()==Qt::Key_W){
            teclapresionada='w';
        }
        else if(teclita->key()==Qt::Key_A){
            teclapresionada='a';
        }
        else if(teclita->key()==Qt::Key_S){
            teclapresionada='s';
        }
        else if(teclita->key()==Qt::Key_D){
            teclapresionada='d';
        }
        else if(teclita->key()==Qt::Key_Q){
            emit salirMenu(); //Cambio debido al menu
            return;
        }
        else{
            return;
        }
    /*
    //ocupo actualizar para que se realize el movimiento correspondiente internamente
    motorJuego->actualizar(teclapresionada);
    //como necesito que mi pantalla se actualize ocupo update pa avizarle que cambio
    //y que corra denuevo
    update();
    */ // CAMBIOS PARA LA FUSION ENTRE PREGUNTAS Y MAPA
    if (motorJuego->actualizar(teclapresionada)) {
        update();
        if (motorJuego->hay_colision()) {
            emit colisionEnemigoDetectada();
        } else if (motorJuego->meta_alcanzada()){
            emit metaAlcanzada();
        }
    }
}












