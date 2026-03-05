#include "MyRenderer2D.h"
#include <algorithm>

void MyRenderer2D::beginFrame(){
    drawQueue.clear();
    // ClearBackground(clearColor); should be in engine::run()
} //clears the draw queue for the new frame

void MyRenderer2D::setCamera(const MyCamera2D& cam){
    myCam = cam;
} //lets the game / engine set or modify the camera used for rendering
        
void MyRenderer2D::submitSprite(const Texture2D& tex, const TransformComponent& tf, int layer){
    DrawCommand newRequest;

    newRequest.type = DrawCommandType::Sprite;
    newRequest.tf = tf;
    newRequest.layer = layer;
    newRequest.texture = tex;

    drawQueue.emplace_back(newRequest);
} //adds a sprite draw request into the queue. renderer does nto draw immediately; it stores the request
        
void MyRenderer2D::submitTextScreen(const std::string& text, Vector2 screenPos, int fontSize, Color color, int layer){
    DrawCommand newRequest;

    newRequest.type = DrawCommandType::Text;
    newRequest.text = text;
    newRequest.screenPos = screenPos;
    newRequest.fontSize = fontSize;
    newRequest.color = color;
    newRequest.layer = layer;

    drawQueue.emplace_back(newRequest);

} //queues UI/debug text in screen space
        
void MyRenderer2D::flush(){
    std::sort(drawQueue.begin(), drawQueue.end(), [](const DrawCommand& a, const DrawCommand& b) {return a.layer < b.layer;}
    );

    for (const DrawCommand& cmd : drawQueue) {
        if (cmd.type == DrawCommandType::Sprite) {
            // World-space sprite: convert world pos -> screen pos using camera
            Vector2 screenPos = myCam.WorldToScreen(cmd.tf.pos);
    
            // Simple draw (position only). Later you can upgrade to rotation/scale.
            DrawTexture(cmd.texture, (int)screenPos.x, (int)screenPos.y, WHITE);
        } else { // Text
            DrawText(cmd.text.c_str(), (int)cmd.screenPos.x, (int)cmd.screenPos.y, cmd.fontSize, cmd.color);
        }
    }
} //sorts queued requests by layer, then draws themn in order. sprites use camera world -> screen conversion; UI text does not
        
void MyRenderer2D::setClearColor(Color c){
    clearColor = c;
}