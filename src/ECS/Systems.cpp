#include "Systems.h"

void renderSystem(World& world, MyRenderer2D& renderer, MyAssetManager& assets){
    for(const auto& spritePair : world.getSpriteStorage()){
        //check if there is a transform entity, check if entity exists in transformStorage
        Entity e = spritePair.first;
        const SpriteComponent& sprite = spritePair.second;

        if(world.hasTransform(e)){
            
            TransformComponent& tf = world.getTransform(e);
            Texture2D& tex = assets.getTexture(sprite.textureKey);
            renderer.submitSprite(tex, tf, sprite.layer);
        }
    }
}