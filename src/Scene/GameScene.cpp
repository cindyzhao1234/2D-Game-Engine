// DemoScene.cpp
#include "GameScene.h"

#include "../ECS/Systems.h"   // movementSystem, renderSystem

void GameScene::onEnter(EngineContext& ctx) {
    // Bind inputs (demo-scene local bindings)
    ctx.input.bindKey("MoveLeft",  KEY_A);
    ctx.input.bindKey("MoveRight", KEY_D);
    ctx.input.bindKey("MoveUp",    KEY_W);
    ctx.input.bindKey("MoveDown",  KEY_S);

    ctx.input.bindKey("Back", KEY_ESCAPE);

    // Load textures once (adjust paths to your setup)
    // If you're running from build/, "../" is common.
    ctx.assetManager.loadTexture("background", "../background.png");
    ctx.assetManager.loadTexture("player",     "../player.png");
    ctx.assetManager.loadTexture("NPC",        "../kettleTest.png");

    // Spawn ECS entities
    background = ctx.myWorld.createEntity();
    ctx.myWorld.addSprite(background, {"background", 0});
    ctx.myWorld.addTransform(background, {{0.0f, 0.0f}, 0.0f, {1.0f, 1.0f}});

    player = ctx.myWorld.createEntity();
    ctx.myWorld.addSprite(player, {"player", 10});
    ctx.myWorld.addTransform(player, {{100.0f, 100.0f}, 0.0f, {1.0f, 1.0f}});

    npc = ctx.myWorld.createEntity();
    ctx.myWorld.addSprite(npc, {"NPC", 10});
    ctx.myWorld.addTransform(npc, {{200.0f, 200.0f}, 0.0f, {1.0f, 1.0f}});
}

void GameScene::onExit(EngineContext& ctx) {
    // Clean up entities created by this scene
    if (background) ctx.myWorld.destroyEntity(background);
    if (player)     ctx.myWorld.destroyEntity(player);
    if (npc)        ctx.myWorld.destroyEntity(npc);

    background = player = npc = 0;

    // Optional: you can unload textures here, but many engines keep assets cached globally.
    // ctx.assetManager.unloadTexture("background");
    // ctx.assetManager.unloadTexture("player");
    // ctx.assetManager.unloadTexture("NPC");
}

void GameScene::update(float dt, EngineContext& ctx) {
    // Back to menu
    if (ctx.input.wasPressed("Back")) {
        ctx.scenes.changeScene(std::make_unique<MenuScene>());
        return;
    }

    // Move the player entity (ECS system)
    movementSystem(ctx.myWorld, player, ctx.input, dt, speed);
}

void GameScene::draw(EngineContext& ctx) {
    // Render all entities with Transform+Sprite
    renderSystem(ctx.myWorld, ctx.myRenderer, ctx.assetManager);

    // HUD text
    ctx.myRenderer.submitTextScreen(hudText, {30.0f, 30.0f}, 18, DARKGRAY, hudLayer);
}