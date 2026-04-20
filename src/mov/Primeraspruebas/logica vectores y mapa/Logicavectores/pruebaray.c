#include<stdio.h>
#include "raylib.h"

int main(){
    const int screenaltura= 550;
    const int screenancho=800;

    InitWindow(screenancho,screenaltura,"pruebita de pantalla");
    SetTargetFPS(60);

    while (!WindowShouldClose()){
        BeginDrawing();
            ClearBackground(DARKBLUE);
            DrawText("veamo que tal chat",300,250,20,DARKBROWN);
        EndDrawing();

        /* code */
    }
    
    return 0;
}