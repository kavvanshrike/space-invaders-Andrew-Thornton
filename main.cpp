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
#include "Enemy.h"
#include <iostream>
int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Texture2D backgroundTexture = LoadTexture("images/SpaceShooterAssetPack_BackGrounds.png");
    Texture2D shipTexture = LoadTexture("images/SpaceShooterAssetPack_Ships.png");
    Texture2D bulletTexture = LoadTexture("images/SpaceShooterAssetPack_Projectiles.png");
    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    Background background(&backgroundTexture, 100);
    Player player(&shipTexture, 500, &bulletTexture, 0.25f);
    //Enemy enemy(&shipTexture,50, 50, 500, &bulletTexture, 32,16);
    const int ENEMIES_PER_ROW = 11;
    const int ENEMIES_PER_COL = 5;
    const int TOTAL_ENEMIES = ENEMIES_PER_ROW * ENEMIES_PER_COL;
    Enemy* enemies[TOTAL_ENEMIES];
    for (int x = 0; x < ENEMIES_PER_ROW; x++)//asign enemy formation
    {
        for (int y = 0; y < ENEMIES_PER_COL; y++)
        {
            enemies[x + (y * ENEMIES_PER_ROW)] = new Enemy(&shipTexture, x * (GetScreenWidth() / ENEMIES_PER_ROW), y * (GetScreenHeight() / ENEMIES_PER_COL/ 3)+50, 
                /*speed*/20.0f, 
                /*offset*/32.0f,
                /*delay*/0.25f,
                &bulletTexture, 32 + (y * 8), 16);
        }
    }
    //Bullet bullet(&bulletTexture,0,0, 300);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        background.Update();
        player.Update();
        for (int i = 0; i < TOTAL_ENEMIES; i++)
            enemies[i]->Update();
        //enemy.Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        ClearBackground(BLACK);
        background.Draw();
        player.Draw();
        for (int i = 0; i < TOTAL_ENEMIES; i++)
            enemies[i]->Draw();
        //enemy.Draw();
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