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


	// Draw
	BeginDrawing();
	    
	    ClearBackground(RAYWHITE);
	    DrawCircleV(ballPosition, 50, ballColor);

	EndDrawing();
    }

}
