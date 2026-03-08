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

void movementSystem(World& world, Entity player, Input& input, float dt, float speed){
    /*
    - gets player’s Transform
    - checks input actions
    - updates transform.pos using speed * dt

    (Only affects the player entity for now.)
    */

    if(!world.hasTransform(player)){
        return;
    } 

    TransformComponent& playerTf = world.getTransform(player);

    if(input.isDown("MoveLeft")){
        // DrawText("A pressed", 10, 40, 16, BLACK);
        playerTf.pos.x -= speed * dt;
    }

    if(input.isDown("MoveRight")){
        // DrawText("D pressed", 10, 40, 16, BLACK);
        playerTf.pos.x += speed * dt;
    }

    if(input.isDown("MoveUp")){
        // DrawText("W pressed", 10, 40, 16, BLACK);
        playerTf.pos.y -= speed * dt;
    }

    if(input.isDown("MoveDown")){
        // DrawText("S pressed", 10, 40, 16, BLACK);
        playerTf.pos.y += speed * dt;
    }

}