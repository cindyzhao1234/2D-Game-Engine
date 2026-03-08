#include "MyAssetManager.h"
#include <iostream>
#include <cassert>
#include <string>

Texture2D& MyAssetManager::getTexture(const std::string& key){
    if(storage.find(key) != storage.end()){
        return storage.at(key);
    }
    else{
        assert(false && "texture not loaded");
        std::abort();
    }
} //returns a reference to a texture already loaded. if key doens't exist, error or load it if you also know file path.

Texture2D& MyAssetManager::loadTexture(const std::string& key, const std::string& filePath){
    if(storage.find(key) != storage.end()){
        return storage.at(key);
    } else{
        Texture2D loadedTexture = LoadTexture((assetsRoot + filePath).c_str());
        storage.insert({key, loadedTexture});
        return storage.at(key);
    }
}// if key is not in map, load from filePath and store into map. if key exists, return already loaded texture

bool MyAssetManager::hasTexture(const std::string& key) const{
    if(storage.find(key) != storage.end()){
        return true;
    }
    return false;
} //returns whether the texture is already loaded/cached

void MyAssetManager::unloadAll(){
    for(auto const& pair : storage){
        UnloadTexture(pair.second);
    }
    storage.clear();
} //loop through every cached texture and calls raylib unload. call in Engine::shutdown();

size_t MyAssetManager::textureCount() const{
    return storage.size();
} //returns how many textures currently loaded. used to confirm not duplicating loads

void MyAssetManager::unloadTexture(const std::string& key){
    auto it = storage.find(key);
    if(it != storage.end()){
        UnloadTexture(it->second);
        storage.erase(it);
    }
} //unload texture by one key

void MyAssetManager::setAssetsRoot(const std::string& root){
    assetsRoot = root;

    if (!assetsRoot.empty() && assetsRoot.back() != '/' && assetsRoot.back() != '\\') {
        assetsRoot.push_back('/');
    }
}