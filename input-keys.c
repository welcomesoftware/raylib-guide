/*******************************************************************************
 * raylib [core] example - Gamepad input moves the ball
 ******************************************************************************/

#include <raylib.h>

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Establece que la pantalla utilice anti-aliasing para el suavizado de 
    // los bordes de los objetos.
    SetConfigFlags(FLAG_MSAA_4X_HINT);

    InitWindow(screenWidth, screenHeight, "Gamepad moves ball");
    SetTargetFPS(60);

    // Variables
    // Creamos una variable que contenga las coordenadas de nuestro player y
    // lo pocicionamos al centro de la pantalla.
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    // Main game loop
    while(!WindowShouldClose())
    {
        // Update
        // Detecta la entrada de las flechas de dirección del teclado y actualiza
        // la posición del jugagor en base a las flecha presionadas
        if(IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
        if(IsKeyDown(KEY_LEFT)) ballPosition.x -= 3.0f;
        if(IsKeyDown(KEY_UP)) ballPosition.y -= 3.0f;
        if(IsKeyDown(KEY_DOWN)) ballPosition.y += 3.0f;

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
        
        // Draw
        BeginDrawing();
            // Establece en fondo de pantalla blanco hueso
            ClearBackground(RAYWHITE);
            
            // Dibuja al jugador en la posición que se esta actualizando 
            // en Update constantemente.
            DrawCircleV(ballPosition, 50, MAROON);

        EndDrawing();
    }
    
    // De-Initialization
    CloseWindow();

    // Finish the program
    return 0;
}
