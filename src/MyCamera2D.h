#pragma once
#include <raylib.h>

struct MyCamera2D{
    Vector2 pos = {0.0f, 0.0f};
    float zoom = 1.0f;

    //The following methods are placed in the struct or the function will NOT know which camera to modify, unless it takes a Camera2D& operator.
    void setPos(Vector2 worldPos);
    void setZoom(float newZoom);
    Vector2 WorldToScreen(Vector2 worldPos);
    Vector2 ScreenToWorld(Vector2 screenPos);
};

