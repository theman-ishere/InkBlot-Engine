#pragma once
#include <SDL2/SDL.h>
#include "Entity.hpp"
class Entity; // Forward declaration of the Entity class

class RenderWindow {
public:
    RenderWindow(const char* p_title, int p_w, int p_h);
    ~RenderWindow();
    void clear();
    void render(Entity& entity);
    void display();
    void cleanUp();

    SDL_Renderer* getRenderer() const; // Marked as const here

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};
