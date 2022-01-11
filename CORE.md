# raylib [CORE] - Introduction

El módulo **[CORE]** de *raylib* se encarga del manejo de las ventanas, cursor,
dibujado de objetos en pantalla, ya sea modelos 3d u objetos 2d, sistemas de 
cámaras 2d y 3d, sistemas de simulacion de realidad virtual, sistemas de manejo
de sombreadores, funciones relacionadas con el espacio en pantalla, funciones 
relacionadas con el manejo del tiempo, funciones aleatorias, de captura de 
pantalla, funciones relacionadas con el manejo de archivos desde el disco duro
funciones relacionadas con compresion y codificación de archivos, entrada de 
datos por teclado, mouse, sistema táctil o joystick, etc.

La mejor manera de aprender o desarrollar una disciplina es prácticar, así que
manos a la obra:

## Basic window - Ventana básica

```
/***************************************************
 * raylib [core] example - Basic window
 ***************************************************/

// librerías necesaria
#include <raylib>

int main() 
{
    // Initialization

    // Define los valores de ancho y alto de la ventana
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Inicializa la ventana con los valores de ancho y alto y el titulo
    InitWindow(screenWidth, screenHeight, "Basic window");

    // Inicializa nuestro juego a 60 frames por segundo
    SetTargetFPS(60);
    
    // Ciclo principal del juego
    while(!WindowShouldClose())     // Detecta si cierra la ventana o si presiona Esc
    {
        // Update
        // Las variables del juego se actualizan aquí


        // Draw
        // Los elementos en pantalla se dibujan aquí
        BeginDrawing();
            
            // Limpia la ventana y establece el fondo en color blanco hueso
            ClearBackground(RAYWHITE);

            // Dibuja un texto en la ventana en las coordenadas x:190, y:200, font:20, color:LIGHTGRAY
            DrawText("Has creado tu primera ventana!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

    // Finaliza la inicialización
    // Cierra la ventana y los gráficos OpenGL
    CloseWindow();

    // Finaliza el programa
    return 0;
}

```
