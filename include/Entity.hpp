#pragma once // Include guard to prevent multiple inclusion of this header file
#include <SDL2/SDL.h> // Include SDL library
#include <SDL2/SDL_image.h> // Include SDL image library

// Class definition for Entity
class Entity
{

public:
	// Constructor for Entity class
	Entity(float p_x, float p_y, SDL_Texture* p_tex);
	
	// Getter function for x-coordinate
	float getX();
	
	// Getter function for y-coordinate
	float getY();
	
	// Getter function for texture
	SDL_Texture* getTex();
	
	// Getter function for current frame rectangle
	SDL_Rect getCurrentFrame();

private:
    float x, y; // Coordinates of the entity
    SDL_Rect currentFrame; // Current frame rectangle
    SDL_Texture* tex; // Texture of the entity
};
