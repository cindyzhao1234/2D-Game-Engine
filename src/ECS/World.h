#pragma once
#include "Entity.h"
#include "Components.h"

#include <unordered_map>
//owns entity crration / destruction, component storage maps

class World{
    public:
        Entity createEntity(); //returns a new ID

        void destroyEntity(Entity e); //removes all components for that entity and frees the ID

        TransformComponent& addTransform(Entity e, const TransformComponent& t); //attaches transform to eneity (stores a copy)

        bool hasTransform(Entity e) const; //check existence

        TransformComponent& getTransform(Entity e) const; //access it(assume exists, assert otherwise)

        SpriteComponent& addSprite(Entity e, const SpriteComponent& s);

        bool hasSprite(Entity e) const;

        SpriteComponent& getSprite(Entity e);

        const std::unordered_map<Entity, SpriteComponent>& getSpriteStorage() const;
        const std::unordered_map<Entity, TransformComponent>& getTransformStorage() const;


    private:
        std::unordered_map<Entity, SpriteComponent> spriteStorage;

        std::unordered_map<Entity, TransformComponent> transformStorage;

        Entity nextId = 1; //ID counter
};