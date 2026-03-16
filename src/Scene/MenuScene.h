// MenuScene.h
#pragma once

#include <string>
#include <memory>

#include "Scene.h"          // base Scene
#include "EngineContext.h"  // EngineContext
#include "GameScene.h"      // switching target

class MenuScene : public Scene {
public:
    void onEnter(EngineContext& ctx) override;
    void onExit(EngineContext& ctx) override;

    void update(float dt, EngineContext& ctx) override;
    void draw(EngineContext& ctx) override;

private:
    std::string title = "COZY DEMO";
    std::string prompt = "Press START (e.g. E / Enter) to play";
    bool startPressed = false;
};