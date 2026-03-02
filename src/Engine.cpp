#include <iostream>
#include <raylib.h>
#include "Engine.h"

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
    while(!WindowShouldClose() && running){
        //update dt using raylib's frame time
        dt = GetFrameTime();
        //draw calls
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10,10);
        EndDrawing();
    }
}

void Engine::shutdown(){
    CloseWindow();
    running = false;
}