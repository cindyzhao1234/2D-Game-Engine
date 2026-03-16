#include "Input.h"

void Input::bindKey(const std::string& actionName, KeyboardKey k){
    //k is passed by value (a copy)
    keyActions[actionName] = k;
}

void Input::bindMouse(const std::string& actionName, MouseButton button){
    //k is passed by value (a copy)
    mouseActions[actionName] = button;
}

bool Input::GetKey(const std::string& actionName, KeyboardKey& k){
    //k is passed by reference. if passed without &, GetKey would only change a local copy
    auto it = keyActions.find(actionName);

    if(it == keyActions.end()){
        return false;
    }

    k = it -> second;
    return true;
}

bool Input::GetMouse(const std::string& actionName, MouseButton& button){
    //k is passed by reference. if passed without &, GetKey would only change a local copy
    auto it = mouseActions.find(actionName);

    if(it == mouseActions.end()){
        return false;
    }

    button = it -> second;
    return true;
}


bool Input::isDown(const std::string& actionName){    
    KeyboardKey k;
    MouseButton button;
    if(!GetKey(actionName, k)){
        if(!GetMouse(actionName, button)){
            return false;
        }
        return IsMouseButtonDown(button);
    }
    return IsKeyDown(k);

}

bool Input::wasPressed(const std::string& actionName){
    KeyboardKey k;
    MouseButton button;
    //the KeyboardKey value, first is the action name string
    if(!GetKey(actionName, k)){
        if(!GetMouse(actionName, button)){
            return false;
        }
        return IsMouseButtonPressed(button);
    }
    
    return IsKeyPressed(k);
}