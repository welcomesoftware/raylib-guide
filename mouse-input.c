/*******************************************************************************
 * raylib [core] example - Mouse input
 ******************************************************************************/

#include <raylib.h>

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Mouse input");

    Vector2 ballPosition = {screenWidth/2, screenHeight/2};
    Color ballColor = DARKBLUE;
    
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose())
    {
        // Update
        ballPosition = GetMousePosition();
        
        if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)) ballColor = DARKBLUE;
        else if(IsMouseButtonDown(MOUSE_BUTTON_MIDDLE)) ballColor = LIME;
        else if(IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) ballColor = RED;

        // Draw
        BeginDrawing();
          
            ClearBackground(RAYWHITE);
            DrawCircleV(ballPosition, 50, ballColor);

            DrawRectangle(5, 5, 230, 50, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(5, 5, 230, 50, BLUE);
            DrawText("INSTRUCCIONES:", 15, 10, 10, BLACK);
            DrawText("MUEVA LA BOLA CON EL MOUSE", 15, 25, 10, DARKGRAY);
            DrawText("HAGA CLICK PARA CAMBIAR EL COLOR", 15, 40, 10, DARKGRAY);

        EndDrawing();
    }

}
