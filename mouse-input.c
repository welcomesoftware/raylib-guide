/*******************************************************************************
 * raylib [core] example - Mouse input
 ******************************************************************************/

#include <raylib.h>

int main()
{
    // Initialization
    //--------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    SetConfigFlags(FLAG_MSAA_4X_HINT);      // Anti-aliasing flags

    InitWindow(screenWidth, screenHeight, "Mouse input");

    // Player variables
    Vector2 ballPosition = {screenWidth/2, screenHeight/2};
    Color ballColor = DARKBLUE;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------

    // Main game loop
    while(!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------
        ballPosition = GetMousePosition();  // Obtiene la posicion del mouse
        
        // Dependiendo del boton presionado cambia el color de la bola
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) ballColor = DARKBLUE;
        else if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) ballColor = LIME;
        else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) ballColor = RED;
        //----------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------
        BeginDrawing();
            
            ClearBackground(RAYWHITE);
            
            // Dibuja la bola en la posición, tamaño y color 
            DrawCircleV(ballPosition, 50, ballColor);
            
            // Dibuja un rectángulo y en lugar de color le pasa una función
            // fade() la cual agrega una transparencia determinada a un color
            // que nosotros elijamos.
            DrawRectangle(5, 5, 230, 50, Fade(SKYBLUE, 0.5f));
            // Dibuja un rectángulo sin relleno, solo sus lineas
            DrawRectangleLines(5, 5, 230, 50, BLUE);

            DrawText("INSTRUCCIONES:", 15, 10, 10, BLACK);
            DrawText("MUEVA LA BOLA CON EL MOUSE", 15, 25, 10, DARKGRAY);
            DrawText("HAGA CLICK PARA CAMBIAR EL COLOR", 15, 40, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------
    CloseWindow();      // Cierra la ventana 

    // Finaliza el programa
    return 0;
}
