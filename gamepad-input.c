/*******************************************************************************
 * raylib [core] - Gamepad input
 ******************************************************************************/

#include <raylib.h>

// NOTE: Gamepad name ID depends on drivers and OS
#define XBOX360_LEGACY_ID       "Xbox Controller"

#if defined(PLATFORM_RPI)
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#else 
    #define XBOX360_NAME_ID     "Microsoft X-Box 360 pad"
    #define PS3_NAME_ID         "PLAYSTATION(R)3 Controller"
#endif

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT);      // Set MSAA 4X hint Anti-aliasing
    InitWindow(screenWidth, screenHeight, "Gamepad Input");
     
    Texture2D texPs3pad = LoadTexture("resources/ps3.png");
    Texture2D texXboxpad = LoadTexture("resources/xbox.png");

    SetTargetFPS(60);

    // Main game loop
    while(!WindowShouldClose()) 
    {
        // Update
        if(IsKeyDown(KEY_F11)) ToggleFullscreen();

        // Draw
        BeginDrawing();
            ClearBackground(RAYWHITE);

            if(IsGamepadAvailable(0)) 
            {
                DrawText(TextFormat("GAMEPAD: [%s]", GetGamepadName(0)), 10, 10, 10, BLACK);
                DrawTexture(texPs3pad, 0, 0, MAROON);

                // Draw buttons: ps
                if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_MIDDLE)) DrawCircle(396, 222, 13, RED);

                // Draw buttons: basics
                DrawRectangle(328, 170, 32, 13, BLACK);
                DrawTriangle((Vector2){436, 168}, (Vector2){436,185}, (Vector2){464,177}, BLACK);
                DrawCircle(557, 144, 13, BLACK);
                DrawCircle(586, 173, 13, BLACK);
                DrawCircle(557, 203, 13, BLACK);
                DrawCircle(527, 173, 13, BLACK);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_MIDDLE_LEFT) DrawRectangle(328, 170, 32, 13, RED);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_MIDDLE_RIGHT) DrawTriangle((Vector2){436, 168}, (Vector2){436,185}, (Vector2){464,177}, RED);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_RIGHT_FACE_UP) DrawCircle(557, 144, 13, LIME);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_RIGHT_FACE_RIGHT) DrawCircle(586, 173, 13, RED);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_RIGHT_FACE_DOWN) DrawCircle(557, 203, 13, BLUE);
                if(GetGamepadButtonPressed() == GAMEPAD_BUTTON_RIGHT_FACE_LEFT) DrawCircle(527, 173, 13, PINK);

                // Draw buttons: d-pad
                DrawRectangle(225, 132, 24, 84, BLACK);
                DrawRectangle(195, 161, 84, 25, BLACK);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_LEFT_FACE_UP) DrawRectangle(225, 132, 24, 29, RED);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_LEFT_FACE_DOWN) DrawRectangle(225, 132 + 54, 24, 30, RED);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_LEFT_FACE_LEFT) DrawRectangle(195, 161, 30, 25, RED);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_LEFT_FACE_RIGHT) DrawRectangle(195 + 54, 161, 30, 25, RED);

                // Draw buttons: left-right back buttons
                DrawRectangle(220, 55, 50, 10, BLACK);
                DrawRectangle(525, 55, 50, 10, BLACK);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_LEFT_TRIGGER_1) DrawRectangle(220, 55, 50, 10, RED);
                if (GetGamepadButtonPressed() == GAMEPAD_BUTTON_RIGHT_TRIGGER_1) DrawRectangle(525, 55, 50, 10, RED);
                // Draw axis: left-right triggers
                DrawRectangle(220, 42, 50, 10, RED);
                DrawRectangle(525, 42, 50, 10, RED);
                DrawRectangle(220, 42, 50, (((1 - (int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_TRIGGER))/2)*10), GRAY);
                DrawRectangle(525, 42, 50, (((1 - (int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_TRIGGER))/2)*10), GRAY); 

                // Draw axis: left joystick
                DrawCircle(319, 255, 35, BLACK);
                DrawCircle(319, 255, 31, LIGHTGRAY);
                DrawCircle(319 + ((int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_X)*20),
                           255 + ((int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_LEFT_Y)*20), 25, BLACK);

                // Draw axis: right joystick
                DrawCircle(475, 255, 35, BLACK);
                DrawCircle(475, 255, 31, LIGHTGRAY);
                DrawCircle(475 + ((int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_X)*20),
                           255 + ((int)GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y)*20), 25, BLACK);

                // Draw Gamepad axis info
                DrawText(TextFormat("DETECTED AXIS [%i]:", GetGamepadAxisCount(0)), 10, 50, 10, MAROON);

                for (int i = 0; i < GetGamepadAxisCount(0); i++)
                {
                    DrawText(TextFormat("AXIS %i: %.02f", i, GetGamepadAxisMovement(0, i)), 20, 70 + 20*i, 10, DARKGRAY);
                }
                
                if (GetGamepadButtonPressed() != -1) DrawText(TextFormat("DETECTED BUTTON: %i", GetGamepadButtonPressed()), 10, 430, 10, RED);
                else DrawText("DETECTED BUTTON: NONE", 10, 430, 10, GRAY); 

                // DrawText(TextFormat("D-PAD TEST: %i", GAMEPAD_BUTTON_LEFT_FACE_DOWN), 10, 410, 10, GRAY);
            } 
            else {
                DrawText("GAMEPAD: NOT DETECTED", 10, 10, 10, MAROON);
                DrawText("CONNECT ANY GAMEPAD NOW...", 10, 25, 10, GRAY);
                DrawTexture(texXboxpad, 0, 0, LIGHTGRAY);
            }

        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(texPs3pad);
    UnloadTexture(texXboxpad);

    CloseWindow();
    
    // Finaliza el programa
    return 0;
}
