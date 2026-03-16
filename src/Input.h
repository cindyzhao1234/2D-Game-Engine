#pragma once
#include <iostream>
#include <unordered_map>
#include "raylib.h"

class Input{
    public:
        void bindKey(const std::string& actionName, KeyboardKey k);
        void bindMouse(const std::string& actionName, MouseButton button);
        bool isDown(const std::string& actionName);
        bool wasPressed(const std::string& actionName);
        bool GetKey(const std::string& actionName, KeyboardKey& k);
        bool GetMouse(const std::string& actionName, MouseButton& button);

    private:
        //for some games which dont use WASD, bind the keys in init. However, some games might n ot use wasd. in that case, use input.bind() to bind custom keybinds in the script for the game.
        //input.bind() will overwrite the old binding. if actionName already exists, it replaces the keyboard key
        std::unordered_map<std::string, KeyboardKey> keyActions{
            {"MoveLeft", KEY_A},
            {"MoveRight", KEY_D},
            {"MoveUp", KEY_W},
            {"MoveDown", KEY_S},
            {"Interact", KEY_E},
            {"Jump", KEY_SPACE},
        };

        std::unordered_map<std::string, MouseButton> mouseActions{
            {"LeftClick", MOUSE_BUTTON_LEFT},
        };
};