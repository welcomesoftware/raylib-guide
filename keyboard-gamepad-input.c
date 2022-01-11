/*******************************************************************************
 * raylib [core] example - Gamepad input moves the ball
 ******************************************************************************/

#include <raylib.h>

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Gamepad moves ball");
    SetTargetFPS(60);

    // Variables
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

    // Main game loop
    while(!WindowShouldClose())
    {
        // Update
        if(IsKeyDown(KEY_RIGHT)) ballPosition.x += 3.0f;
        if(IsKeyDown(KEY_LEFT)) ballPosition.x -= 3.0f;
        if(IsKeyDown(KEY_UP)) ballPosition.y -= 3.0f;
        if(IsKeyDown(KEY_DOWN)) ballPosition.y += 3.0f;

        if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) ballPosition.x += 3.0f;
        if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) ballPosition.x -= 3.0f;
        if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) ballPosition.y -= 3.0f;
        if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) ballPosition.y += 3.0f;

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawCircleV(ballPosition, 50, MAROON);
        EndDrawing();
    }
    
    // De-Initialization
    CloseWindow();

    // Finish the program
    return 0;
}
