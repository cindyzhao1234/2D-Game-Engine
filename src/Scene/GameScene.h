// DemoScene.h
#pragma once

#include <string>
#include <memory>

#include "Scene.h"
#include "EngineContext.h"
#include "MenuScene.h"

#include "../ECS/Entity.h"   // Entity type

class GameScene : public Scene {
public:
    void onEnter(EngineContext& ctx) override;
    void onExit(EngineContext& ctx) override;

    void update(float dt, EngineContext& ctx) override;
    void draw(EngineContext& ctx) override;

private:
    Entity background = 0;
    Entity player = 0;
    Entity npc = 0;

    float speed = 300.0f;

    std::string hudText = "DemoScene: WASD move | Esc = back to menu";
    int hudLayer = 1000;
};