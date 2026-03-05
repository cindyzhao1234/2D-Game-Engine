#include "Input.h"

void Input::bind(const std::string& actionName, KeyboardKey k){
    //k is passed by value (a copy)
    actions[actionName] = k;
}

bool Input::GetKey(const std::string& actionName, KeyboardKey& k){
    //k is passed by reference. if passed without &, GetKey would only change a local copy
    auto it = actions.find(actionName);

    if(it == actions.end()){
        return false;
    }

    k = it -> second;
    return true;
}

bool Input::isDown(const std::string& actionName){    
    KeyboardKey k;
    if(!GetKey(actionName, k)){
        return false;
    }
    return IsKeyDown(k);

}

bool Input::wasPressed(const std::string& actionName){
    KeyboardKey k;
    //the KeyboardKey value, first is the action name string
    if(!GetKey(actionName, k)){
        return false;
    }
    
    return IsKeyPressed(k);
}