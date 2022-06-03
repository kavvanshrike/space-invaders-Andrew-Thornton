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
#include "Shield.h"
#include "Ship.h"
#include <string>
#include <iostream>

//constant definitions
const int ENEMIES_PER_ROW = 11;
const int ENEMIES_PER_COL = 5;
const int TOTAL_ENEMIES = ENEMIES_PER_ROW * ENEMIES_PER_COL;
const int TOTAL_SHIELDS = 4;
const int TOTAL_ENTITIES = 3 + TOTAL_ENEMIES + TOTAL_SHIELDS;

enum EntityIDs {//use enums to order our entity array
    BACKGROUND,
    PLAYER,
    SHIELD_1,
    SHIELD_2,
    SHIELD_3,
    SHIELD_4, 
    MOTHERSHIP
};
enum TextureIDs {//use enums to help assign textures in entity array
    BACKGROUND_TEX,
    SHIPS_TEX,
    PROJECTILE_TEX,
    MISC_TEX
};

void CreateEntities(Entity** ents, Texture2D* textures)//create one array of entities
{
    ents[BACKGROUND] = new Background(&textures[BACKGROUND_TEX], 100);
    ents[PLAYER] = new Player (&textures[SHIPS_TEX], 500, &textures[PROJECTILE_TEX], 0.25f);
    //Ship motherShip(&shipTexture, -64, 25, 50.0f);

    
    int shieldSpacing = (GetScreenWidth() / (TOTAL_SHIELDS + 1));
    for (int i = 0; i <= SHIELD_4-SHIELD_1; i++)
    {
        ents[i + SHIELD_1] = new Shield(&textures[MISC_TEX], shieldSpacing + (i * shieldSpacing) - 32, GetScreenHeight() - 160);
    }
    ents[MOTHERSHIP] = new Ship(&textures[SHIPS_TEX], -64, 25, 50.0f);
    for (int x = 0; x < ENEMIES_PER_ROW; x++)//asign enemy formation
    {
        for (int y = 0; y < ENEMIES_PER_COL; y++)
        {
            ents[x + MOTHERSHIP + 1 + (y * ENEMIES_PER_ROW)] = new Enemy(&textures[SHIPS_TEX], x * (GetScreenWidth() / ENEMIES_PER_ROW), y * (GetScreenHeight() / ENEMIES_PER_COL / 3) + 50,
                /*speed*/20.0f,
                /*offset*/32.0f,
                /*delay*/0.25f,
                &textures[PROJECTILE_TEX], 32 + (y * 8), 16);
        }
    }
}

int GetCollisions(Entity** e, int i)//check for collisions between entities
{
    int score = 0;
    if (i != BACKGROUND && i != PLAYER)//not the background
    {
        score += ((Player*)e[PLAYER])->GetCollisions(e[i]);
    }
    if (i == PLAYER || (i >= SHIELD_1 && i <= SHIELD_4))//checking for collisions with enemy bullets
    {
        for(int a = MOTHERSHIP+1; a < TOTAL_ENTITIES; a++)
            ((Enemy*)e[a])->GetCollisions(e[i]);
    }
    return score;
}

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 800;
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Texture2D textures[4] = {
    LoadTexture("images/SpaceShooterAssetPack_BackGrounds.png"),
    LoadTexture("images/SpaceShooterAssetPack_Ships.png"),
    LoadTexture("images/SpaceShooterAssetPack_Projectiles.png"),
    LoadTexture("images/SpaceShooterAssetPack_Miscellaneous.png"),
    };
    Entity* ents[TOTAL_ENTITIES];
    CreateEntities(ents, textures);
    int score = 0;
    //SetTargetFPS(60);
    //--------------------------------------------------------------------------------------
    
    //Bullet bullet(&bulletTexture,0,0, 300);
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        
        for (int i = 0; i < TOTAL_ENTITIES; i++)
        {
            ents[i]->Update();
            score += GetCollisions(ents, i)/10;
        }
            
        //enemy.Update();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        ClearBackground(BLACK);
        
        for (int i = 0; i < TOTAL_ENTITIES; i++)
            ents[i]->Draw();
        //text rendering
        std::string scoreStr = std::to_string(score);
        DrawText(scoreStr.c_str(), 8, 8, 28, WHITE);//show curent score
        //keep this line in mind for using raylib as it only accepts *const char into the drawtext function

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}