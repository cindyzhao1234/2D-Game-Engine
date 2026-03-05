#include <iostream>
#include <raylib.h>
#include "Engine.h"
#include "Input.h"
#include <ctime>
#include <stdio.h>
#include "TransformComponent.h"

Engine::Engine(){
    //although fpsTarget, dt, and running are under private, any method of the same class can read/write them. but code outside the class cannot do engine.running = true;
    running = false;
    dt = 0;
    fpsTarget = 60;
}

bool Engine::init(int w, int h, const char* title){
    InitWindow(w, h, title);
    SetTargetFPS(fpsTarget);
    running = true;

    return true;
}

void Engine::run(){
    //-----TEST CODE
    TransformComponent playerTransform;
    // Vector2 playerpos = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };
    Input input;
    //--- END TEST CODE

    while(!WindowShouldClose() && running){
        //update dt using raylib's frame time
        dt = GetFrameTime();
        //draw calls
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10,10);
        
        //----------TEST CODE

        
        float speed = 300.0f;
        if(input.isDown("MoveLeft")){
            DrawText("A pressed", 10, 40, 16, BLACK);
            playerTransform.pos.x -= speed * dt;
        }

        if(input.isDown("MoveRight")){
            DrawText("D pressed", 10, 40, 16, BLACK);
            playerTransform.pos.x += speed * dt;
        }

        if(input.isDown("MoveUp")){
            DrawText("W pressed", 10, 40, 16, BLACK);
            playerTransform.pos.y -= speed * dt;
        }

        if(input.isDown("MoveDown")){
            DrawText("S pressed", 10, 40, 16, BLACK);
            playerTransform.pos.y += speed * dt;
        }

        DrawCircle(playerTransform.pos.x, playerTransform.pos.y, 20.0, BLACK);

        // ------- END TEST CODE

        EndDrawing();
    }
}

void Engine::shutdown(){
    CloseWindow();
    running = false;
}