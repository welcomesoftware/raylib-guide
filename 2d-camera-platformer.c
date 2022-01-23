/*******************************************************************************
 * raylib [core] example - 2d camera platformer
 ******************************************************************************/

// Librerías
#include <raylib.h>
#include <raymath.h>

// Definiciones
#define G 400
#define PLAYER_JUMP_SPD 350.0f;
#define PLAYER_HORZ_SPD 200.0f;

// typedefs
typedef struct Player {
    Vector2 position;
    float speed;
    bool canJump;
} Player;

typedef struct EnvItem {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

// Prototipos
void UpdatePlayer(Player *player, EnvItem *envItems, int envItemsLength, float delta);
// Cámara
void UpdateCameraCenter(
        Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
void UpdateCameraCenterInsideMap(
        Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
void UpdateCameraCenterSmoothFollow(
        Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
void UpdateCameraEventOunOnLanding(
        Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);
void UpdateCameraPlayerBoundsPush(
        Camera2D *camera, Player *player, EnvItem *envItems, int envItemsLength, float delta, int width, int height);

int main()
{
    // Inicialización
    //--------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "2d Camera platformer");

    Player player = {0};
    player.position = (Vector2){400,280};
    player.speed = 0;
    player.canJump = false;
    
    EnvItem envItems[] = {
        {{0, 0, 1000, 400}, 0, LIGHTGRAY},
        {{0, 400, 1000, 200}, 1, GRAY},
        {{300, 200, 400, 10}, 1, GRAY},
        {{250, 300, 100, 10}, 1, GRAY},
        {{650, 300, 100, 10}, 1, GRAY}
    }; 
    
    int envItemsLength = sizeof(envItems)/sizeof(envItems[0]);

    Camera2D camera = {0};
    camera.target = player.position;
    camera.offset = (Vector2){screenWidth/2.0f, screenHeight/2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // Establecer apuntadores a las multiples funciones de actualizar camara
    void(*cameraUpdaters[])(Camera2D*, Player*, EnvItem*, int, float, int, int) = {
        UpdateCameraCenter,
        UpdateCameraCenterInsideMap,
        UpdateCameraCenterSmoothFollow,
        UpdateCameraEventOunOnLanding,
        UpdateCameraPlayerBoundsPush
    };

    int cameraOption = 0;
    int cameraUpdatersLength = sizeof(cameraUpdaters)/sizeof(cameraUpdaters[0]);

    char cameraDescriptions[] = {
        "Sigue al jugador",
        "Sigue al jugador pero se adhiere a los bordes de la pantalla",
        "Sigue al jugador pero suavizado",
        "Sigue al jugador horizontalmente, solo lo sigue verticalmente si esta cayendo",
        "El jugador empuja la camara lo mas cerca del borde de la pantalla"
    };

    SetTargetFPS(60);
    //--------------------------------------------------------------------------

    // Ciclo principal del juego
    while(!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------
        float deltaTime = GetFrameTime();

        UpdatePlayer(&player, envItems, envItemsLength, deltaTime);

        camera.zoom += ((float)GetMouseWheelMove()*0.05f);
        if(camera.zoom > 3.0f) camera.zoom = 3.0f;
        else if(camera.zoom < 0.25f) camera.zoom = 0.25f;

        if(IsKeyPressed(KEY_R))
        {
            camera.zoom = 1.0f;
            player.position = (Vector2){400,280};
        }

        if(IsKeyPressed(KEY_C)) cameraOption = (cameraOption + 1)%cameraUpdatersLength;

        // LLama a la funcion de actualizar camara por su propio apuntador
        cameraUpdaters[cameraOption](&camera, &player, envItems, envItemsLength, deltaTime, screenWidth, screenHeight);
        //----------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------
        // TODO: falta hacer la parte del dibujado de objetos en pantalla.

    }
    // Desinicializacion
    CloseWindow();

    // Finaliza con exito
    return 0;
}

// TODO: falta hacer las funciones prototipadas anteriormente
