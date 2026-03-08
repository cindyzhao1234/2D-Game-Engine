#include <iostream>
#include <raylib.h>
#include "Engine.h"
#include "Input.h"
#include <ctime>
#include <stdio.h>
#include "ECS/Components.h"
#include "MyRenderer2D.h"
#include "MyAssetManager.h"
#include "ECS/World.h"
#include "ECS/Systems.h"
#include "ECS/Entity.h"


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
    World world;

    Entity background = world.createEntity();
    world.addSprite(background, {"background", 0});
    world.addTransform(background, {{100.0, 100.0}, 0.0, {1.0, 1.0}});
    Entity player = world.createEntity();
    world.addSprite(player, {"player", 10});
    world.addTransform(player, {{100.0, 100.0}, 0.0, {1.0, 1.0}});

    Entity NPC = world.createEntity();
    world.addSprite(NPC, {"NPC", 10});
    world.addTransform(NPC, {{200.0, 200.0}, 0.0, {1.0, 1.0}});

    MyAssetManager assetManager;

    assetManager.loadTexture("background", "../background.png");
    assetManager.loadTexture("player", "../player.png");
    assetManager.loadTexture("NPC", "../kettleTest.png");

    Input input;
    MyRenderer2D renderer;
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

        movementSystem(world, player, input, dt, speed);
        renderer.beginFrame();

        renderSystem(world, renderer, assetManager);

        renderer.flush();


        // assetManager.unloadAll();
        // ------- END TEST CODE

        EndDrawing();
    }
}

void Engine::shutdown(){
    CloseWindow();
    running = false;
}