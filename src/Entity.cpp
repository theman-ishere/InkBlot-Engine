#include "Entity.hpp" // Include custom Entity header file
#include <SDL2/SDL.h> // Include SDL library
#include <SDL2/SDL_image.h> // Include SDL image library

// Constructor for Entity class
Entity::Entity(float p_x, float p_y, SDL_Texture* p_tex)
:x(p_x), y(p_y), tex(p_tex)
{
	currentFrame.x = 0; // Set initial x-coordinate of current frame
	currentFrame.y = 0; // Set initial y-coordinate of current frame
	currentFrame.w = 32; // Set width of current frame
	currentFrame.h = 32; // Set height of current frame
}

// Getter function for x-coordinate
float Entity::getX()
{
	return x; // Return x-coordinate
}

// Getter function for y-coordinate
float Entity::getY()
{
	return y; // Return y-coordinate
}

// Getter function for texture
SDL_Texture* Entity::getTex()
{
	return tex; // Return texture
}

// Getter function for current frame rectangle
SDL_Rect Entity::getCurrentFrame()
{
	return currentFrame; // Return current frame rectangle
}
