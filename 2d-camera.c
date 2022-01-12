/********************************************************************************
 *  raylib [core] example - 2d camera
 *******************************************************************************/

// Librerias
#include <raylib.h>

// Defines
#define MAX_BUILDINGS   100

int main()
{
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;
    InitWindow(screenWidth, screenHeight, "2d camera");
    
    // Jugador y edificios
    Rectangle player = {400, 280, 40, 40};
    Rectangle buildings[MAX_BUILDINGS] = {0};
    Color buildColors[MAX_BUILDINGS] = {0};

    int spacing = 0;
    
    // Esta función crea un agrello de 100 edificios con valores y colores
    // aleatorios entre cada uno; y los posiciona uno al par del otro.
    for(int i = 0; i < MAX_BUILDINGS; i++) {
        buildings[i].width = (float)GetRandomValue(50,200);
        buildings[i].height = (float)GetRandomValue(100,800);
        buildings[i].y = screenHeight - 130.0f - buildings[i].height;
        buildings[i].x = -6000.0f + spacing;

        spacing += (int)buildings[i].width;
        
        buildColors[i] = (Color){ 
            GetRandomValue(200,240), 
            GetRandomValue(200, 250), 
            GetRandomValue(200, 250),
            255 
        };
    }
    
    // Camara configuración
    Camera2D camera = {0};
    camera.target = (Vector2){ player.x + 20.0f, player.y + 20.0f };
    camera.offset = (Vector2){ screenWidth/2.0f, screenHeight/2.0f };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while(!WindowShouldClose())     // Detecta el cerrar la ventana
    {
        // Update
        //------------------------------------------------------------
        // Movimiento del pesonaje con joystick
        if(IsGamepadAvailable(0)) 
        {
            if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) player.x += 2;
            else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) player.x -= 2;

            // Control de rotación de la camara
            if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_TRIGGER_1)) camera.rotation--;
            else if(IsGamepadButtonDown(0, GAMEPAD_BUTTON_RIGHT_TRIGGER_1)) camera.rotation++;

            // Control de zoom de la camara
            camera.zoom += ((float)GetGamepadAxisMovement(0, GAMEPAD_AXIS_RIGHT_Y) * -0.05f);

            if(GetGamepadButtonPressed() == 17) {
                camera.zoom = 0.1f;
                camera.rotation = 0.0f;
            }

        }

        // Movimiento del pesonaje con teclado
        if(IsKeyDown(KEY_RIGHT)) player.x += 2;
        else if(IsKeyDown(KEY_LEFT)) player.x -= 2;

        // control de rotación de la camara
        if(IsKeyDown(KEY_A)) camera.rotation--;
        else if(IsKeyDown(KEY_S)) camera.rotation++;

        // Camara sigue al player
        camera.target = (Vector2){ player.x + 20, player.y + 20 };
        
        // Limites de la rotación de camara 80 grados (-40 a 40)
        if(camera.rotation > 40) camera.rotation = 40;
        else if(camera.rotation < -40) camera.rotation = -40;

        // Control de zoom de la camara
        camera.zoom += ((float)GetMouseWheelMove() * 0.05f);
        
        // Limites del zoom de la camara
        if(camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if(camera.zoom < 0.1f) camera.zoom = 0.1f;

        // Resetear camara
        if(IsKeyPressed(KEY_R)) {
            camera.zoom = 0.1f;
            camera.rotation = 0.0f;
        }
        //------------------------------------------------------------

        // Draw
        //------------------------------------------------------------
        BeginDrawing();
            ClearBackground(RAYWHITE);
            BeginMode2D(camera);
                // Dibuja el suelo
                DrawRectangle(-6000, 320, 13000, 8000, DARKGRAY);

                // Dibuja los edificios
                for(int i = 0; i < MAX_BUILDINGS; i++) 
                    DrawRectangleRec(buildings[i], buildColors[i]);

                DrawRectangleRec(player, MAROON);
            EndMode2D();
            
            DrawText("SCREEN AREA", 640, 10, 20, RED);
            DrawRectangle(10, 10, 250, 113, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines(10, 10, 250, 113, BLUE);
            
        EndDrawing();
    }
    // De-Initialization
    CloseWindow();
    
    // Finaliza el programa
    return 0;
}
