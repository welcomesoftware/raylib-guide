/*******************************************************************************
 * raylib [physac] example - Physics movement
 *******************************************************************************/

#include <raylib.h>

#define PHYSAC_IMPLEMENTATION
#include <physac.h>

#define VELOCITY 0.5f

int main()
{
    // Initialization
    //--------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    
    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "Physics movement");
    
    // Initialize physics and default physics bodies
    InitPhysics();

    // Create floor, wall, rectangle physics bodies
    PhysicsBody floor = CreatePhysicsBodyRectangle((Vector2){screenWidth/2.0f, (float)screenHeight}, (float)screenWidth, 100, 10);
    PhysicsBody platformLeft = CreatePhysicsBodyRectangle((Vector2){ screenWidth*0.25f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody platformRight = CreatePhysicsBodyRectangle((Vector2){ screenWidth*0.75f, screenHeight*0.6f }, screenWidth*0.25f, 10, 10);
    PhysicsBody wallLeft = CreatePhysicsBodyRectangle((Vector2){ -5, screenHeight/2.0f }, 10, (float)screenHeight, 10);
    PhysicsBody wallRight = CreatePhysicsBodyRectangle((Vector2){ (float)screenWidth + 5, screenHeight/2.0f }, 10, (float)screenHeight, 10);

    // Disable dynamics to floor and walls physics bodies
    floor->enabled = false;
    platformLeft->enabled = false;
    platformRight->enabled = false;
    wallLeft->enabled = false;
    wallRight->enabled = false;

    // Create movement physics body
    PhysicsBody player = CreatePhysicsBodyRectangle((Vector2){screenWidth/2.0f, screenHeight/2.0f}, 50, 50, 1);
    player->freezeOrient = true;
    
    SetTargetFPS(60);
    //--------------------------------------------------------------------------

    // Main game loop
    while(!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------
        UpdatePhysics();        // Update physics system
        
        // Horizontal movement input
        if(IsKeyDown(KEY_RIGHT)) player->velocity.x = VELOCITY;
        else if(IsKeyDown(KEY_LEFT)) player->velocity.x = -VELOCITY;
        // Vertical movement input checking if player physics body is grounded
        if(IsKeyDown(KEY_UP) && player->isGrounded) player->velocity.y = -VELOCITY*4;
        //----------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------
        BeginDrawing();
            ClearBackground(BLACK);
            
            // Draw created physics bodies
            int bodiesCount = GetPhysicsBodiesCount();
            for(int i = 0; i < bodiesCount; i++) {
                PhysicsBody player = GetPhysicsBody(i);
                int vertexCount = GetPhysicsShapeVerticesCount(i);
                for(int j = 0; j < vertexCount; j++) {
                    Vector2 vertexA = GetPhysicsShapeVertex(player, j);
                    int jj = (((j + 1) < vertexCount) ? (j + 1) : 0);
                    Vector2 vertexB = GetPhysicsShapeVertex(player, jj);
                    DrawLineV(vertexA, vertexB, GREEN);
                }
            }

        EndDrawing();
        //----------------------------------------------------------------------
    }
    ClosePhysics();
    CloseWindow();
    return 0;
}
