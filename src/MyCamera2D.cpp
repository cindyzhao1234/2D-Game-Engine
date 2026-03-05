#include "MyCamera2D.h"

void MyCamera2D::setPos(Vector2 worldPos){
    pos = worldPos;
}

void MyCamera2D::setZoom(float newZoom){
    zoom = newZoom;
}

Vector2 MyCamera2D::WorldToScreen(Vector2 worldPos){
    Vector2 screenCenter = { (float)GetScreenWidth() * 0.5f,(float)GetScreenHeight() * 0.5f };
    Vector2 relative = {worldPos.x - pos.x, worldPos.y - pos.y};
    Vector2 scaled = {relative.x * zoom, relative.y * zoom};

    return {screenCenter.x + scaled.x, screenCenter.y + scaled.y};

}

Vector2 MyCamera2D::ScreenToWorld(Vector2 screenPos){
    Vector2 screenCenter = { (float)GetScreenWidth() * 0.5f, (float)GetScreenHeight() * 0.5f };

    Vector2 delta = {screenPos.x - screenCenter.x, screenPos.y - screenCenter.y};

    Vector2 worldDelta = {delta.x / zoom, delta.y / zoom};

    return {pos.x + worldDelta.x, pos.y + worldDelta.y};
}