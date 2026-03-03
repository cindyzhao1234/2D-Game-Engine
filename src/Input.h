#pragma once
#include <iostream>
#include <unordered_map>
#include "raylib.h"

class Input{
    public:
        void bind(const std::string& actionName, KeyboardKey k);
        bool isDown(const std::string& actionName);
        bool wasPressed(const std::string& actionName);
        bool GetKey(const std::string& actionName, KeyboardKey& k);

    private:
        //for some games which dont use WASD, bind the keys in init. However, some games might n ot use wasd. in that case, use input.bind() to bind custom keybinds in the script for the game.
        //input.bind() will overwrite the old binding. if actionName already exists, it replaces the keyboard key
        std::unordered_map<std::string, KeyboardKey> actions{
            {"MoveLeft", KEY_A},
            {"MoveRight", KEY_D},
            {"MoveUp", KEY_W},
            {"MoveDown", KEY_S},
            {"Interact", KEY_E},
            {"Jump", KEY_SPACE},
        };
};