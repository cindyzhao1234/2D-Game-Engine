// MenuScene.cpp
#include "MenuScene.h"

void MenuScene::onEnter(EngineContext& ctx) {
    // Optional: set a background clear colour for the menu
    // ctx.renderer.setClearColor(RAYWHITE);

    // Optional: menu-specific bindings (only if you want them here instead of Engine init)
    // ctx.input.bind("Start", KEY_E);
}

void MenuScene::onExit(EngineContext& ctx) {
    // Nothing to clean up yet (menu has no entities).
    (void)ctx;
}

void MenuScene::update(float dt, EngineContext& ctx) {
    (void)dt;

    // Switch to the game scene when Start is pressed
    if ( ctx.input.wasPressed("Interact") || ctx.input.wasPressed("LeftClick")) {
        startPressed = true;
    }


}

void MenuScene::draw(EngineContext& ctx) {
    if (!startPressed) {
        ctx.myRenderer.submitTextScreen(prompt, {60.0f, 110.0f}, 18, DARKGRAY, 1000);
    } else {
        ctx.myRenderer.submitTextScreen("Start pressed! Scene system works.", {60.0f, 110.0f}, 18, DARKGREEN, 1000);
    }
}