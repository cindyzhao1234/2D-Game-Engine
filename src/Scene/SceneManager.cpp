// SceneManager.cpp
#include "SceneManager.h"

void SceneManager::setInitial(std::unique_ptr<Scene> scene, EngineContext& ctx) {
    pending.reset();
    current = std::move(scene);
    if (current) current->onEnter(ctx);
}

void SceneManager::changeScene(std::unique_ptr<Scene> scene) {
    pending = std::move(scene);
}

void SceneManager::update(float dt, EngineContext& ctx) {
    // Apply deferred scene change safely (not mid-scene update)
    if (pending) {
        if (current) current->onExit(ctx);
        current = std::move(pending);
        current->onEnter(ctx);
    }

    if (current) {
        current->update(dt, ctx);
    }
}

void SceneManager::draw(EngineContext& ctx) {
    if (current) {
        current->draw(ctx);
    }
}