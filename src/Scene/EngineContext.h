#pragma once
#include "../MyRenderer2D.h"
#include "../Input.h"
#include "../MyAssetManager.h"
#include "../ECS/World.h"
// #include "../Scene/SceneManager.h"

//engine owns systems, scenes uses systems

//EngineContext gives access to the real copy of each engine system, without copying them
class SceneManager;

struct EngineContext{
    Input& input;
    MyRenderer2D& myRenderer;
    World& myWorld;
    MyAssetManager& assetManager;
    SceneManager& scenes;
};