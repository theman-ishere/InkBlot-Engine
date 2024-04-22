#include <iostream> // Include for std::cout and std::endl
#include "RenderWindow.hpp"

// Definition of the constructor
RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    : window(nullptr), renderer(nullptr)
{
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);

    if (window == nullptr)
    {
        std::cout << "Window failed to init. Error: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

// Definition of the getRenderer() method
SDL_Renderer* RenderWindow::getRenderer() {
    return renderer;
}

// Definition of the clear() method
void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

// Definition of the render(Entity&) method
void RenderWindow::render(Entity& entity) {
    entity.render(renderer);
}

// Definition of the display() method
void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}
