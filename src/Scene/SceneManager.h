// SceneManager.h
#pragma once

#include <memory>

#include "Scene.h"
#include "EngineContext.h"

class SceneManager {
public:
    // Sets the first scene and immediately enters it.
    void setInitial(std::unique_ptr<Scene> scene, EngineContext& ctx);

    // Request a scene change (applied safely at the start of the next update()).
    void changeScene(std::unique_ptr<Scene> scene);

    // Applies any pending scene change, then updates current scene.
    void update(float dt, EngineContext& ctx);

    // Draw current scene (no scene switching here).
    void draw(EngineContext& ctx);

private:
    std::unique_ptr<Scene> current;
    std::unique_ptr<Scene> pending;
};