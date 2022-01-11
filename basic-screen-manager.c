/*******************************************************************************
 * raylib [core] example - Basic screen manager
 *******************************************************************************/

#include <raylib.h>

// Types and structures definition
typedef enum GameScreen { LOGO = 0, TITLE, GAMEPLAY, ENDING } GameScreen;

int main() 
{
    // Initializacion
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Basic screen manager");
    SetTargetFPS(60);
    GameScreen currentScreen = LOGO;

    // Initialize variables
    int framesCounter = 0;          // useful to count frames

    // Main game loop
    while(!WindowShouldClose())     // Detect window close
    {
        // Update
        switch(currentScreen)
        {
            case LOGO:
            {
                // TODO: Update LOGO screen variables here!
                framesCounter++;
                
                // Wait for 5 seconds (300 frames) before jumping to TITLE screen
                if(framesCounter > 300)
                {
                    currentScreen = TITLE;
                }
            } break;

            case TITLE:
            {
                // TODO: Update LOGO screen variables here!
                
                // Press enter to change GAMEPLAY screen
                if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = GAMEPLAY;
                }
            } break;

            case GAMEPLAY:
            {
                // TODO: Update GAMEPLAY screen variables here!

                // Press enter to change ENDING screen
                if(IsKeyPressed(KEY_ENTER) || IsGestureDetected(GESTURE_TAP))
                {
                    currentScreen = ENDING;
                }
            } break;

            case ENDING:
            {
                if(IsKeyPressed(KEY_ESCAPE))
                {
                    break;
                }
            } break;

            default: break;
        }

        // Draw
        BeginDrawing();
        
            ClearBackground(RAYWHITE);
            
            switch(currentScreen)
            {
                case LOGO:
                   // TODO: Draw LOGO screen here!
                   DrawText("WELCOME 2D JUNGLE GAMEDEVELOP", 20, 20, 40, BEIGE);
                   DrawText("Espere unos segundos...", 290, 220, 20, GRAY);
                   break;

                case TITLE:
                   // TODO: Draw TITLE screen here!
                   ClearBackground(BLACK);
                   DrawText("WELCOME TO MARS", 20, 20, 40, WHITE);
                   DrawText("Mars is realy blue", 20, 60, 20, BLUE);
                   break;
                
                case GAMEPLAY:
                   ClearBackground(BLACK);
                   DrawText("READY TO PLAY", 290, 220, 40, PURPLE);
                   DrawText("Are you ready player one...", 290, 260, 20, YELLOW);
                   break;

                case ENDING:
                   ClearBackground(BLACK);
                   DrawText("Game Over", 290, 220, 40, WHITE);
                   DrawText("Press ESC to exit", 290, 260, 20, WHITE);
                   break;
            }
        EndDrawing();
    }
    
    CloseWindow();    
    return 0;
}
