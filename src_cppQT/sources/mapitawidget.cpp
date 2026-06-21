#include<mapitawidget.h>


//este es el constructor de mi objeto aqui le pongo setfocuspolicy para indicarle a la ventana
//q este bien despierta pa que reciba todas las teclas que el jugador aprete
maponW::maponW(juego* j,QWidget* padre)
    :QWidget(padre),motorJuego(j),pixelsize(30)
{
    setFocusPolicy(Qt::StrongFocus);

    fotoplayer.load("C:/gitchulini/RUTA/fototriplec/wekeche");
    fotoene.load("C:/gitchulini/RUTA/fototriplec/nicki");

}

void maponW::paintEvent(QPaintEvent* evento){
    QPainter painter(this);


    //parto ocupando todos los metodos nuevos que defini pa sacar la info
    //y similar a la funcion dibujar anterior con 2 ciclos for para recorrer todo mi mapa
    //y con logica de ifs y else ifs para saber si dibujar al jugador , enemigo, muros o mapa
    int dimensionnow=motorJuego->obtdimensionmapa();
    int posxjug=motorJuego->obtjugX();
    int posyjug=motorJuego->obtjugY();
    int posxene=motorJuego->obteneX();
    int posyene=motorJuego->obteneY();

    for(int i=0;i<dimensionnow;i++){
        for(int j=0;j<dimensionnow;j++){
            QRect rect(j*pixelsize,i*pixelsize,pixelsize,pixelsize);

            if(j==posxjug && i==posyjug){
                painter.setBrush(QBrush(Qt::blue));
                painter.setPen(Qt::NoPen);
                painter.drawPixmap(rect,fotoplayer);


            }
            else if(j == posxene && i == posyene){
                painter.setBrush(QBrush(Qt::red));
                painter.setPen(Qt::NoPen);
                painter.drawPixmap(rect,fotoene);
            }
            else if(motorJuego->obtcasillamapa(j,i)=='#'){
                painter.setBrush(QBrush(Qt::black));
                painter.setPen(Qt::NoPen);
                painter.drawRect(rect);
            }
            else{
                painter.setBrush(QBrush(Qt::lightGray));
                painter.setPen(Qt::NoPen);
                painter.drawRect(rect);
            }
        }
    }

}

void maponW::keyPressEvent(QKeyEvent* teclita) {
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
            this->close();
            return;
        }
        else{
            return;
        }



    //ocupo actualizar para que se realize el movimiento correspondiente internamente
    motorJuego->actualizar(teclapresionada);
    //como necesito que mi pantalla se actualize ocupo update pa avizarle que cambio
    //y que corra denuevo
    update();
}












