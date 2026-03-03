# 2D-Game-Engine

brew install raylib

"Universal" means reusable systems, not universal gameplay

git submodule

transform gets read/written all the time, so making it public speeds up development 
input bindings are changed rarely and the map structure is an implementation detail.

ECS (Entity Component System) is a, architecture pattern (a way to organise game code) so we dont end up with a giant inheritance tree. many existing engines / frameworks are ECS style
1. Entity = "a thing"
    Entity 1 = player, Entity 2 = tree, etc
    By itself, an entity has no data and no behaviour

2. COmponent = "Data about a thing"
    small data structs you attach to entities, transform, sprite, velocity, collider
    e.g: tree entity has transform + sprite, player has transform + sprute + velcoity + collider

3. Systrem = behaviour that runs over entities
    systems are the code that operates on entities that have certain components:
    MovementSYstem: needs velocity + transform --> updates position each frame
    RenderSystem needs transfor + sprite
    CollisionSyste, needs collider and transform

Instead of writing logic inside a Player class and NPC class etc, you write small components that hold data and systems that are reusable and apply to many entities

classic OOP approach: Model game objects as classes with behaviour: Player class with update() draw(), same for enemy etc. Often end up with inheritance: CHaracter -> Player/ENemy/NPC
- Problem that appears over time is that behaviour gets duplicated or tangled. Adding new combinations of behaviour becomes enemy

ECS:
- Cleaner separation of concerns. movement logic lives in MovementSystem, not scattered across lots of classes
- Easier to add new features. If you want an entity tro be interactable, just add an Interactable component to it.

TransformComponent groups the "spacial state" of an object in one place.

Renderer2D:
- Rather than the game code calling DrawTexture, it should call the engine API like renderer.draw()