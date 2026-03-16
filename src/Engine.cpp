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
#include "Scene/SceneManager.h"
#include "Scene/MenuScene.h"


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

// void Engine::run(){

//     while(!WindowShouldClose() && running){
//         //update dt using raylib's frame time
//         dt = GetFrameTime();
//         //draw calls
//         BeginDrawing();
//         ClearBackground(WHITE);
//         DrawFPS(10,10);
        
//         EndDrawing();
//     }
// }

void Engine::run(){
    World world;
    
    MyAssetManager assetManager;
    assetManager.loadTexture("background", "../background.png");
    assetManager.loadTexture("player", "../player.png");
    assetManager.loadTexture("NPC", "../kettleTest.png");
    
    Entity background = world.createEntity();
    world.addSprite(background, {"background", 0});
    world.addTransform(background, {{100.0f, 100.0f}, 0.0f, {1.0f, 1.0f}});
    
    Entity player = world.createEntity();
    world.addSprite(player, {"player", 10});
    world.addTransform(player, {{100.0f, 100.0f}, 0.0f, {1.0f, 1.0f}});
    
    Entity npc = world.createEntity();
    world.addSprite(npc, {"NPC", 10});
    world.addTransform(npc, {{200.0f, 200.0f}, 0.0f, {1.0f, 1.0f}});
    
    Input input;
    MyRenderer2D renderer;
    SceneManager scenes;
    EngineContext ctx{input, renderer, world, assetManager, scenes};

    scenes.setInitial(std::make_unique<MenuScene>(), ctx);
    
            //update dt using raylib's frame time
    while (!WindowShouldClose() && running) {
        dt = GetFrameTime();
            //draw calls
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10,10);
    
        float speed = 300.0f;
    
        movementSystem(world, player, input, dt, speed);
    
        BeginDrawing();
        ClearBackground(WHITE);
        DrawFPS(10, 10);
    
        renderer.beginFrame();
        renderSystem(world, renderer, assetManager);
        scenes.update(dt, ctx);
        scenes.draw(ctx);
        renderer.flush();
    
        EndDrawing();
    }
}
    

void Engine::shutdown(){
    CloseWindow();
    running = false;
}