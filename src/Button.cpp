#include "Button.hpp"

Button::Button(SDL_Renderer* renderer, int x, int y, int width, int height, SDL_Color color)
    : renderer(renderer), x(x), y(y), width(width), height(height), color(color), clicked(false) {}

void Button::handleEvent(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN && !clicked) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (mouseX >= x && mouseX <= x + width && mouseY >= y && mouseY <= y + height) {
            clicked = true;
            std::cout << "Button clicked!" << std::endl;
        }
    }
}

void Button::render() {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = { x, y, width, height };
    SDL_RenderFillRect(renderer, &rect);
}

bool Button::isClicked() {
    return clicked;
}
