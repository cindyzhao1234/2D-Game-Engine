#pragma once
#include "EngineContext.h"

//abstract class and cannot be instantiated

class Scene{
    public:
        virtual ~Scene() = default; //a destructor for the scene class, runs automatically when an object is getting destroyed
        /*
        when you switch scenes, the old scee gets destroyed to free memory.
        if ~Scene() is nto virtual, C++ might only run the base destructor:
        ~Scene() and DOES NOT run ~GameScene(). Bas because GameScene might own extra stuff that needs clean up

        Imagine Scene* is a label on a box that just says “Scene”.
        Inside the box could be a “MenuScene” or “GameScene”.

        When you throw the box away:
            •	without virtual destructor: you only do the “Scene cleanup”
            •	with virtual destructor: you open the box and do the correct cleanup for what’s actually inside (Menu or Game)
        */

        virtual void onEnter(EngineContext&) = 0; //allcoate and set up scene state, such as spawn entities, spawn asserts, set camera
        
        virtual void onExit(EngineContext&) = 0; //cleanup scene state
        
        virtual void update(float dt, EngineContext&) = 0; //update gameplay logic (movement system, input checks, scene transitions)
        
        virtual void draw(EngineContext&) = 0; //submit render commands, NOT beginDrawing / endDrawing

};