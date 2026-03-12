#include "World.h"

#include <iostream>
#include <cassert>

Entity World::createEntity(){
    Entity newEntity = nextId;
    nextId++;
    
    return newEntity;
} //returns a new ID

void World::destroyEntity(Entity e){
    spriteStorage.erase(e);
    transformStorage.erase(e);
} //removes all components for that entity and frees the ID

TransformComponent& World::addTransform(Entity e, const TransformComponent& t){
    auto result = transformStorage.emplace(e,t);
    auto it = result.first;

    return it->second;
} //attaches transform to entity (stores a copy)

bool World::hasTransform(Entity e) const{
    if(transformStorage.find(e) != transformStorage.end()){
        return true;
    }
    return false;
} //check existence

TransformComponent& World::getTransform(Entity e) const{
    auto it = transformStorage.find(e);

    assert(it != transformStorage.end());

    return it->second;
} //access it(assume exists, assert otherwise)

SpriteComponent& World::addSprite(Entity e, const SpriteComponent& s){
    auto result = spriteStorage.emplace(e, s);
    auto it = result.first;
    
    return it->second;
}

bool World::hasSprite(Entity e) const{
    if(spriteStorage.find(e) != spriteStorage.end()){
        return true;
    }
    return false;
}

SpriteComponent& World::getSprite(Entity e){
    auto it = spriteStorage.find(e);

    assert(it != spriteStorage.end());

    return it->second;
}

const std::unordered_map<Entity, SpriteComponent>& World::getSpriteStorage() const{
    return spriteStorage;
}

const std::unordered_map<Entity, TransformComponent>& World::getTransformStorage() const{
    return transformStorage;
}