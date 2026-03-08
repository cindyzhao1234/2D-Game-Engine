#pragma once

#include <raylib.h>
#include <unordered_map>
#include <string>

class MyAssetManager{
    public:
        Texture2D& getTexture(const std::string& key); //returns a reference to a texture already loaded. if key doens't exist, error or load it if you also know file path.
        Texture2D& loadTexture(const std::string& key, const std::string& filePath);// if key is not in map, load from filePath and store into map. if key exists, return already loaded texture
        bool hasTexture(const std::string& key) const; //returns whether the texture is already loaded/cached
        void unloadAll(); //loop through every cached texture and calls raylib unload. call in Engine::shutdown();
        size_t textureCount() const; //returns how many textures currently loaded. used to confirm not duplicating loads
        void unloadTexture(const std::string& key); //unload texture by one key
        void setAssetsRoot(const std::string& root);

    private:
        std::unordered_map<std::string, Texture2D> storage;
        std::string assetsRoot;
};