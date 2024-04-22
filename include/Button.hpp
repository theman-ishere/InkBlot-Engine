#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SDL2/SDL.h> // Include SDL library
#include <SDL2/SDL_image.h> // Include SDL image library
#include <iostream> // Include input/output stream library

class Button {
private:
    SDL_Renderer* renderer;
    int x, y, width, height;
    SDL_Color color;
    bool clicked;

public:
    Button(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color);
    void handleEvent(SDL_Event& event);
    void render();
    bool isClicked();
};

#endif // BUTTON_HPP
