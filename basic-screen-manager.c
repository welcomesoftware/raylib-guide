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

    // Aquí se crea una variable de tipo ventana, de la cual definimos cuatro
    // enumeraciones en la linea 8, y decidimos que la primera ventana que se
    // verá es la de logo
    GameScreen currentScreen = LOGO;

    // Initialize variables
    // creamos un contadore de frames que nos servira para situaciones en las
    // que tengamos que medir tiempo
    int framesCounter = 0;          // useful to count frames

    // Main game loop
    while(!WindowShouldClose())     // Detect window close
    {
        // Update
        // Toda la lógica del juego o aplicación se produce en esta parte
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
        EndDrawing();
    }
    
    CloseWindow();    
    return 0;
}
