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

### Conceptos nuevos:

Añadimos una nueva variable de tipo GameScreen para controllar en que pantalla
nos encontramos, y declaramos cuantas pantallas queramos en nuestro juego.

```
// Types and structures definition
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// Aquí se crea una variable de tipo ventana, de la cual definimos cuatro
// enumeraciones en la linea 8, y decidimos que la primera ventana que se
// verá es la de logo
GameScreen currentScreen = LOGO;
```

Creamos un contador de frames que nos vendra bién para manipular tiempos de 
espera, entre otras cosas.

```
// creamos un contador de frames que nos servira para situaciones en las
// que tengamos que medir tiempo
int framesCounter = 0;          // useful to count frames
```

Luego vamos al lugar donde sucede la magia; por fin hacemos uso de la sección
update: que es donde toda la lógica del juego se ejecuta.

```
// Update
// Toda la lógica del juego o aplicación se produce en esta parte
switch(currentScreen)
{
    case LOGO:
        // TODO: Update LOGO screen variables here!
        framesCounter++;
        // Wait for 5 seconds (300 frames) before jumping to TITLE screen
        if(framesCounter > 300) currentScreen = TITLE;
        break;

    case TITLE:
        // TODO: Update LOGO screen variables here!
        // Press enter to change GAMEPLAY screen
        if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
        currentScreen = GAMEPLAY;
        break;

    case GAMEPLAY:
        // TODO: Update GAMEPLAY screen variables here!
        // Press enter to change ENDING screen
        if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) currentScreen = ENDING;
        break;

    case ENDING:
        if(IsKeyPressed(KEY_ESCAPE)) break;
        break;

    default: break;
}
```

En la sección Draw también tendremos un poco de magia, dependiendo que que se
este actualizando en Update:

```
// Al igual que en la sección update, la magia ocurre aquí también
// debido a que debendiendo de en que pantalla se encuente update
// se actualiza y se redibuja aquí.
switch(currentScreen)
{
    case LOGO:
        // TODO: Draw LOGO screen here!
        DrawText("WELCOMESOFTWARE GAMEDEVELOP", 10, 10, 10, GRAY);
        DrawText(TextFormat("ESPERE %i SEGUNDOS...", (int)GetTime()), 10, 20, 10, GRAY);
        break;

    case TITLE:
        // TODO: Draw TITLE screen here!
        DrawRectangle(0, 0, screenWidth, screenWidth, PURPLE);
        DrawText("WELCOME 2D JUNGLE", 10, 10, 10, GOLD);
        DrawText("THE FURY CITY", 10, 20, 10, GOLD);
        DrawText("PRESS ENTER or TAP to JUMP to GAMEPLAY SCREEN", 120, 220, 20, GOLD);
        break;
    
    case GAMEPLAY:
        DrawRectangle(0, 0, screenWidth, screenWidth, DARKGRAY);
        DrawText("LETS GET READY", 10, 10, 10, WHITE);
        DrawText("READY PLAYER ONE...", 10, 20, 10, WHITE);
        DrawText("PRESS ENTER or TAP to JUMP to ENDING SCREEN", 120, 220, 20, WHITE);
        break;

    case ENDING:
        DrawRectangle(0, 0, screenWidth, screenHeight, YELLOW);
        DrawText("GAME OVER", 10, 10, 10, PINK);
        DrawText("PRESS ESC TO EXIT THE GAME", 10, 20, 10, PINK);
        break;
}
```

Hasta aquí hemos cubierto todos los conceptos nuevos del manejador de ventanas,
si algo no te ha quedado claro te invito a que repases lo visto anteriormente, 
aunque si tienes experiencia programando en c, no creo que te sea difícil entenderlo.

**Dos puntos a tomar en cuenta**
    1. La sección Update se dedica a actualizar la lógica o mecanicas de juego 
    como actulizar la posición del jugador, la ventana que se muestra en ese
    momento, el tiempo, etc.
    2. Mientras que la sección Draw se dedica a dibujar en pantalla una y otra
    vez lo que hemos decidido visualizar en pantalla, y que se actualizó en Update. 

Te invito a que vayas al código y veas como quedo el ejercicio, lo reescribas 
desde cero y lo compiles, e incluso juega un poco con el, hasta que te sientas 
a gusto con el tema.

[Ir al código de este ejercicio](/basic-screen-manager.c)

## Input keys - Entrada por teclas (Teclado)

![Input keys](/resources/input-keys.png)
