#include "preguntas.h"
#include "movi.h"

int main(){
    strad(time(NULL));

    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    int opcion_menu=0;
    int maxPreg=0;

    Pregunta* b=cargar_preguntas("archivopregs.txt", &maxPreg);
    if (b==NULL){
        printf("Error: no se pudo cargar el archivo");
        return 1;
    }
    barajar_preguntas(b, maxPreg);

    Jugador j= {MAX_VIDAS, 1, PISTAS_NIVEL, 0, 0};

     // Inicializamos las estructuras
    map m1;
    // Empezamos al jugador en la posición 1,1 para que no aparezca sobre un muro
    movjug p1 = {{1, 1}, 1};
    movjug PE ={{7,9},1} ;
    char tecla = ' ';
    int nivel_actual = 1;
    
    printf("Hola y bienvenido a en juego de preguntas para aprender C\n"); // estos textos se van a ir para la fusion con el apartadodo de mov
    printf("Presina ENTER para continuar... ");
    getchar();
    return 0;
}