#include "SceneManager.h"

void SceneManager::setInitial(std::unique_ptr<Scene> scene, EngineContext& ctx){
    current = std::move(scene);
	current->onEnter(ctx);

} //sets current scene and calls onEnter

void SceneManager::changeScene(std::unique_ptr<Scene> scene, EngineContext& ctx){
    current->onExit(ctx);
    current = std::move(scene);
    current->onEnter(ctx);

}

void SceneManager::update(float dt, EngineContext& ctx){
    current->update(dt, ctx);
}

void SceneManager::draw(EngineContext& ctx){
    current->draw(ctx);
}