#pragma once

#include "../MyRenderer2D.h"
#include "../MyAssetManager.h"
#include "World.h"
#include "../Input.h"

void renderSystem(World& world, MyRenderer2D& renderer, MyAssetManager& assets);

void movementSystem(World& world, Entity player, Input& input, float dt, float speed);