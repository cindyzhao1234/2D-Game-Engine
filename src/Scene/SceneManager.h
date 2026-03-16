#pragma once
#include "Scene.h"
#include "stdio.h"
#include <memory>

class SceneManager{
    public:
        void setInitial(std::unique_ptr<Scene> scene, EngineContext& ctx);
        void changeScene(std::unique_ptr<Scene> scene, EngineContext& ctx);
        void update(float dt, EngineContext& ctx);
        void draw(EngineContext& ctx);
    
    private:
        std::unique_ptr<Scene> current;
};