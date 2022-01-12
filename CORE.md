# [CORE] - Introduction

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

![Basic window](/resources/basic-window.png)

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
Si omitimos los comentarios y las lineas de identado por estilo de programación,
nos daremos cuenta que solo nos tomó 12 lineas de codigo crear nuestra ventana,
si al igual igual que yo, tienes conocimientos de otras librerías, ya sabrás 
que esto no es mucho. La otra parte es que crear ventanas con raylib es sencillo
no requiere de mucha lógica, el unico requisito es saber programar en C o C++,
e incluso puedes cambiar al lenguaje de tu elección porque la librería te permite
desarrollar con mas de 50 lenguajes disponibles.

En este repositorio están los archivos de cada ejercicio para que los puedas
descargar y compilar, e incluso si eres un obsecado como yo, puedes reescribirlos
a tu propio gusto, estilo y forma. La mejor forma de aprender es leer y escribir 
código una y otra vez, hasta que los conceptos queden claros en tu memoria.

[Ir al código de este ejercicio](/basic-window.c)

## Basic screen manager - Manejador de ventanas básico

![Basic screen manager](/resources/basic-screen-manager.png)

En este ejercicio vamos a aprender como funciona un manejador de ventanas 
basico utilizando la librería raylib, e implementarlo en nuestro juego de una
forma sencilla. Omitiré las partes que ya hayan sido explicadas anteriormente o
que no tengan mucha complejidad, así que tendrás que estar atento a cada tema
para que puedas seguirle el ritmo a esta guía.

[Ir al código de este ejercicio](/basic-screen-manager.c)
