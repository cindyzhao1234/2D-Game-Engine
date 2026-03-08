#include "MyCamera2D.h"
#include "../ECS/Components.h"

#include <string>
#include <vector>

enum class DrawCommandType {
    Sprite,
    Text
};

struct DrawCommand {
    DrawCommandType type;
    int layer;

    //Sprite 
    Texture2D texture;
    TransformComponent tf;

    //Text
    std::string text;
    Vector2 screenPos;
    int fontSize;
    Color color;
};

class MyRenderer2D{
    public:
        void beginFrame(); //clears the draw queue for the new frame

        void setCamera(const MyCamera2D& cam); //lets the game / engine set or modify the camera used for rendering
        
        void submitSprite(const Texture2D& tex, const TransformComponent& tf, int layer); //adds a sprite draw request into the queue. renderer does nto draw immediately; it stores the request
        
        void submitTextScreen(const std::string& text, Vector2 screenPos, int fontSize, Color color, int layer); //queues UI/debug text in screen space
        
        void flush(); //sorts queued requests by layer, then draws themn in order. sprites use camera world -> screen conversion; UI text does not
        
        void setClearColor(Color c); //store a background clear colour

    private:
        MyCamera2D myCam; //When setCamera is implemented, it shold copy the passed camera into myCam
        Color clearColor;
        std::vector<DrawCommand> drawQueue;

};

