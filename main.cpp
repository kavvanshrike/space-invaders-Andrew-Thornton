/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Entity.h"
#include "Background.h"
#include "Player.h"
#include "Bullet.h"
int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Texture2D backgroundTexture = LoadTexture("images/SpaceShooterAssetPack_BackGrounds.png");
    Texture2D playerTexture = LoadTexture("images/SpaceShooterAssetPack_Ships.png");
    Texture2D bulletTexture = LoadTexture("images/SpaceShooterAssetPack_Projectiles.png");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    Background background(&backgroundTexture, 100);
    Player player(&playerTexture, 500, &bulletTexture, 0.25f);
    //Bullet bullet(&bulletTexture,0,0, 300);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        background.Update();
        player.Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        ClearBackground(BLACK);
        background.Draw();
        player.Draw();
        DrawText("Congrats! You created your first window!", 190, 200, 20, WHITE);
        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}