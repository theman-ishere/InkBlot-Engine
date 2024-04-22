#include <SDL2/SDL.h> // Include SDL library
#include <SDL2/SDL_image.h> // Include SDL image library
#include <iostream> // Include input/output stream library

#include "RenderWindow.hpp" // Include custom RenderWindow header file
#include "Entity.hpp" // Include custom Entity header file
#include "Button.hpp" // Include custom Button header file

int main(int argc, char* args[])
{
    // Initialize SDL video subsystem
    if (SDL_Init(SDL_INIT_VIDEO) > 0) {
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL image subsystem for PNG images
    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window object with specified title and dimensions
    RenderWindow window("GAME v0.3", 1000, 500);

    // Load grass texture for the game
    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    
    // Create two platform entities with specified positions and the loaded grass texture
    Entity platform1(1, 130, grassTexture); 
    Entity platform2(130, 130, grassTexture);
    
    // Create a button
    Button button(window.getRenderer(), 50, 50, 100, 50, {255, 0, 0, 255}); // Red button

    // Initialize game loop control variable
    bool gameRunning = true;

    // Main game loop
    while (gameRunning)
    {
        // Handle events
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // Check if the event is a quit event
            if (event.type == SDL_QUIT)
                gameRunning = false; // Exit the game loop if quit event is detected
            
            // Handle events for the button
            button.handleEvent(event);
        }

        window.clear(); // Clear the window

        // Render platform entities to the window
        window.render(platform1);
        window.render(platform2);
        
        // Render the button
        button.render();

        window.display(); // Display the rendered content on the window

        // Check if the button is clicked
        if (button.isClicked()) {
            std::cout << "Button clicked!" << std::endl;
        }
    }

    // Clean up resources used by the window
    window.cleanUp();
    
    // Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();

    return 0; // Return 0 to indicate successful execution
}