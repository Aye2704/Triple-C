
#include<stdio.h>
#include "raylib.h"

typedef struct 
{
    Vector2 posicion;
    float velocidad;
}Jugador;

Jugador j1={{100,100},330.0f};

/*acordarse de inicializar los structs antes del main
tmb el vector2 es un struc de raylib para ayudar guarda una posicion x e y
 */

int main(){
    const int screenaltura= 550;
    const int screenancho=800;
    const float radiocirculo=32.0;

/*defino las constantes de mi pantalla y mi circulo*/


    InitWindow(screenancho,screenaltura,"pruebita de pantalla");
    SetTargetFPS(60);
    while (!WindowShouldClose()){
        float dt=GetFrameTime();
        Vector2 nuevo ={0,0};
        if (IsKeyDown(KEY_RIGHT)){
            nuevo.x+=1;}
        if(IsKeyDown(KEY_LEFT)){
            nuevo.x+=-1;}
        if (IsKeyDown(KEY_UP)){
            nuevo.y+=-1;}
        if (IsKeyDown(KEY_DOWN)){
            nuevo.y+=1;}
/*toda la parte de aqui es logica de movimiento para que el vector se mueva
y aqui abajito esta lo que es como se actualiza la variable para poder
mover el circulo*/
        j1.posicion.x+= nuevo.x *j1.velocidad *dt;
        j1.posicion.y+= nuevo.y *j1.velocidad *dt;

/*saco las variables para tener mi maximo de ancho y alto*/
        float maxancho=GetScreenWidth();
        float maxalt=GetScreenHeight();

        if(j1.posicion.x<0+radiocirculo){
            j1.posicion.x=0+radiocirculo;
        }
        if(j1.posicion.x>maxancho-radiocirculo){
            j1.posicion.x=maxancho-radiocirculo;
        }
        if(j1.posicion.y<0+radiocirculo){
            j1.posicion.y=0+radiocirculo;
        }
        if(j1.posicion.y>maxalt-radiocirculo){
            j1.posicion.y=maxalt-radiocirculo;
        }
/*toda esta parte de la logica es para que mi circulo no salga de mi pantalla*/
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(j1.posicion,radiocirculo,BLACK);
        EndDrawing();
/*aqui dibujo mi circulo que se va actualizando con mi posicion*/
    }
    return 0;
}