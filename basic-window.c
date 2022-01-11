/****************************************************************************
 * raylib [core] example - Basic window
 ****************************************************************************/

#include <raylib.h>

int main() 
{
    // Initializacion
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib - Basic window");
    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose())     // Detect window close or ESC key
    {
        // Update
        // TODO: Update your variables here

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Congrats! You created your first window", 190, 200, 20, BEIGE);
        EndDrawing();
    }

    // De-Initializacion
    CloseWindow();
    return 0;
}
