#pragma once

class Engine{
    public: //public means other code(like main.cpp) is allowed to create the following:
        Engine(); //constructor, runs automatically when an Engine object is created. Job is to set up object's initial state (defaults)
        bool init(int w, int h, const char* title); //to open a game window, usually needs width, height, title (window name). init retuls bool as it can fail
        void run();
        void shutdown();
    private:
        int fpsTarget;
        float dt; //delta time, time that passed since the previous frame, usually measured in seconds
        bool running;
};