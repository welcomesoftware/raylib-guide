# [CORE] - Introducción

El módulo **[CORE]** de *raylib* se encarga del manejo de las ventanas, cursor,
dibujado de objetos en pantalla, ya sea modelos 3d u objetos 2d, sistemas de 
cámaras 2d y 3d, sistemas de simulación de realidad virtual, sistemas de manejo
de sombreadores, funciones relacionadas con el espacio en pantalla, funciones 
relacionadas con el manejo del tiempo, funciones aleatorias, de captura de 
pantalla, funciones relacionadas con el manejo de archivos desde el disco duro
funciones relacionadas con compresión y codificación de archivos, entrada de 
datos por teclado, mouse, sistema táctil o joystick, etc.

La mejor manera de aprender o desarrollar una disciplina es practicar, así que
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
nos daremos cuenta que solo nos tomó 12 lineas de código crear nuestra ventana,
si al igual igual que yo, tienes conocimientos de otras librerías, ya sabrás 
que esto no es mucho. La otra parte es que crear ventanas con raylib es sencillo
no requiere de mucha lógica, el único requisito es saber programar en C o C++,
e incluso puedes cambiar al lenguaje de tu elección porque la librería te permite
desarrollar con mas de 50 lenguajes disponibles.

En este repositorio están los archivos de cada ejercicio para que los puedas
descargar y compilar, e incluso si eres un obcecado como yo, puedes reescribirlos
a tu propio gusto, estilo y forma. La mejor forma de aprender es leer y escribir 
código una y otra vez, hasta que los conceptos queden claros en tu memoria.

[Ir al código de este ejercicio](/basic-window.c)

## Basic screen manager - Manejador de ventanas básico

![Basic screen manager](/resources/basic-screen-manager.png)

En este ejercicio vamos a aprender como funciona un manejador de ventanas 
básico utilizando la librería raylib, e implementarlo en nuestro juego de una
forma sencilla. Omitiré las partes que ya hayan sido explicadas anteriormente o
que no tengan mucha complejidad, así que tendrás que estar atento a cada tema
para que puedas seguirle el ritmo a esta guía.

### Conceptos nuevos:

Añadimos una nueva variable de tipo GameScreen para controlar en que pantalla
nos encontramos, y declaramos cuantas pantallas queramos en nuestro juego.

```
// Types and structures definition
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

// Aquí se crea una variable de tipo ventana, de la cual definimos cuatro
// enumeraciones en la linea 8, y decidimos que la primera ventana que se
// verá es la de logo
GameScreen currentScreen = LOGO;
```

Creamos un contador de frames que nos vendrá bien para manipular tiempos de 
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
        if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP)) currentScreen = GAMEPLAY;
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

**Dos puntos a tomar en cuenta:**

    1. La sección Update se dedica a actualizar la lógica o mecánicas de juego 
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

En este ejercicio vamos a aprender como manejar la entrada por teclado para 
manipular el movimiento de un objeto en pantalla. Al igual que antes solo vamos
a ver conocimientos nuevos, omitiré cualquier concepto ya antes visto; si algún
concepto nuevo no queda lo suficientemente claro, siéntete en la obligación de 
notificarme para corregir o esclarecer la explicación, sin embargo, si algún
concepto ya antes visto, repasa las lecciones anteriores para que consolides tus
conocimientos.

### Conceptos nuevos:

Creamos una variable tipo Vector2 (Vector en dos dimensiones) que nos permitirá
manipular coordenadas en dos ejes: (x, y). Esto servirá de mucha utilidad para 
controlar el movimiento de nuestro personaje.

```
// Variables
// Creamos una variable que contenga las coordenadas de nuestro player y
// lo pocicionamos al centro de la pantalla.
Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
```
Para manejar la entrada por teclado hacemos uso de la función **IsKeyDown()**
a la cual le pasamos el código de la tecla que queremos recibir **KEY_UP, KEY_DOWN,
KEY_LEFT, KEY_RIGHT,** etc. Esta función verifica si una tecla está siendo
presionada. Los códigos de teclas de teclas son muy predecibles en raylib porque 
el propósito de la librería es que sea fácil de programar.

Por ejemplo: KEY_ESCAPE, KEY_ENTER, KEY_A, KEY_B, KEY_C, etc. Si aun no intuyes
los códigos de teclas; puedes revisar la documentación de la librería donde se
encuentran listados cada uno de los códigos. 
[Códigos de teclas de raylib](https://www.raylib.com/cheatsheet/cheatsheet.html)

```
// Update
// Detecta la entrada de las flechas de dirección del teclado y actualiza
// la posición del jugagor en base a las flecha presionadas
if(IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
if(IsKeyDown(KEY_LEFT)) ballPosition.x -= 3.0f;
if(IsKeyDown(KEY_UP)) ballPosition.y -= 3.0f;
if(IsKeyDown(KEY_DOWN)) ballPosition.y += 3.0f;
```

En esta sección yo me atreví a jugar un poco con el código del programa y añadí
un par de lineas extra para manejo de Gamepad, Joystick o Mando. Si no entiendes
esta parte, no te preocupes debido a que es un tema que no hemos visto y veremos
más adelante, sin embargo no es tan difícil de comprender si usas un poco de 
lógica.

```
// Valida si hay un mando (joystick) conectado y si lo hay detecta su
// entrada y cambia las coordenadas del jugagor en base al movimiento
// de sus flechas.
if(IsGamepadAvailable(0)) 
{
    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) ballPosition.x += 3.0f;
    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) ballPosition.x -= 3.0f;
    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) ballPosition.y -= 3.0f;
    if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) ballPosition.y += 3.0f;
}
```

Entrada por gamepad
====================

    IsGamepadAvailable(): Valida si hay un gamepad disponible en la posicion 0
    IsGamepadButtonDown(): Valida si se esta presionando un botón en el gamepad 0  
    GAMEPAD_BUTTON_LEFT_FACE_UP: Hace referencia al botón d-pad UP
    GAMEPAD_BUTTON_LEFT_FACE_DOWN: Hace referencia al botón d-pad DOWN
    GAMEPAD_BUTTON_LEFT_FACE_LEFT: Hace referencia al botón d-pad LEFT
    GAMEPAD_BUTTON_LEFT_FACE_RIGHT: Hace referencia al botón d-pad RIGHT

Cuando se presiona un botón o una tecla, dependiendo de la dirección se actualiza
la posición de la misma en el vector ballPosition en su eje correspondiente. 
Esto ocurre en la sección Update.

Para ver el listado de referencias a los botones de gamepad debemos leer la
documentación de la librería. 
[raylib.h](https://github.com/raysan5/raylib/blob/master/src/raylib.h) 

Aunque si eres algo perezoso te los dejare aquí
a continuación:

```
// Gamepad buttons
typedef enum {
    GAMEPAD_BUTTON_UNKNOWN = 0,         // Unknown button, just for error checking
    GAMEPAD_BUTTON_LEFT_FACE_UP,        // Gamepad left DPAD up button
    GAMEPAD_BUTTON_LEFT_FACE_RIGHT,     // Gamepad left DPAD right button
    GAMEPAD_BUTTON_LEFT_FACE_DOWN,      // Gamepad left DPAD down button
    GAMEPAD_BUTTON_LEFT_FACE_LEFT,      // Gamepad left DPAD left button
    GAMEPAD_BUTTON_RIGHT_FACE_UP,       // Gamepad right button up (i.e. PS3: Triangle, Xbox: Y)
    GAMEPAD_BUTTON_RIGHT_FACE_RIGHT,    // Gamepad right button right (i.e. PS3: Square, Xbox: X)
    GAMEPAD_BUTTON_RIGHT_FACE_DOWN,     // Gamepad right button down (i.e. PS3: Cross, Xbox: A)
    GAMEPAD_BUTTON_RIGHT_FACE_LEFT,     // Gamepad right button left (i.e. PS3: Circle, Xbox: B)
    GAMEPAD_BUTTON_LEFT_TRIGGER_1,      // Gamepad top/back trigger left (first), it could be a trailing button
    GAMEPAD_BUTTON_LEFT_TRIGGER_2,      // Gamepad top/back trigger left (second), it could be a trailing button
    GAMEPAD_BUTTON_RIGHT_TRIGGER_1,     // Gamepad top/back trigger right (one), it could be a trailing button
    GAMEPAD_BUTTON_RIGHT_TRIGGER_2,     // Gamepad top/back trigger right (second), it could be a trailing button
    GAMEPAD_BUTTON_MIDDLE_LEFT,         // Gamepad center buttons, left one (i.e. PS3: Select)
    GAMEPAD_BUTTON_MIDDLE,              // Gamepad center buttons, middle one (i.e. PS3: PS, Xbox: XBOX)
    GAMEPAD_BUTTON_MIDDLE_RIGHT,        // Gamepad center buttons, right one (i.e. PS3: Start)
    GAMEPAD_BUTTON_LEFT_THUMB,          // Gamepad joystick pressed button left
    GAMEPAD_BUTTON_RIGHT_THUMB          // Gamepad joystick pressed button right
} GamepadButton;
```
Por ultimo hacemos uso de la función DrawCircleV(Vector2, size, color), la cuál
nos dibuja un círculo en un vector que nosotros determinemos. Cada vez que 
presionemos una tecla se actualizará la posición del vector y se re dibujará el
círculo en la nueva posición. Esto ocurre en la sección Draw.

[Ir al código de este ejercicio](/input-keys.c)
