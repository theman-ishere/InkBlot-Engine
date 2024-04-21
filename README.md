# InkBlot Engine

InkBlot Engine is a lightweight 2D game engine designed for creative exploration and rapid development. Built on top of SDL and SDL_image libraries, InkBlot Engine provides an intuitive framework for crafting captivating 2D games.

## Features

- **Effortless Integration:** Seamlessly integrate InkBlot Engine into your development workflow with SDL and SDL_image libraries, allowing you to focus on game design and creativity.

- **Versatile Rendering:** Unlock the full potential of 2D graphics with InkBlot Engine's powerful rendering capabilities. Render sprites, animations, and backgrounds with ease.

- **Resource Management:** Simplify asset management with built-in support for loading and unloading textures, ensuring efficient memory usage and smooth gameplay.

- **User-Friendly API:** InkBlot Engine features a clean and intuitive API that abstracts away complex SDL functionality, making game development accessible to developers of all skill levels.

## Getting Started

To get started with InkBlot Engine, follow these steps:

1. Clone the repository to your local machine:





2. Ensure you have SDL and SDL_image installed on your system. If not, you can download them from the official SDL website:

- [SDL](https://www.libsdl.org/download-2.0.php)
- [SDL_image](https://www.libsdl.org/projects/SDL_image/)

3. Build the engine using your preferred build system (e.g., CMake).

4. Start developing your 2D game using InkBlot Engine!

## Example Usage

```cpp
#include <SDL2/SDL_image.h> // Include SDL image library
#include <iostream> // Include input/output stream library
#include <windows.h> // Include Windows library (not typically used in SDL programs)

#include "RenderWindow.hpp" // Include custom RenderWindow header file
#include "Entity.hpp" // Include custom Entity header file

int main(int argc, char* args[])
{

    if (SDL_Init(SDL_INIT_VIDEO) > 0) // Initialize SDL video subsystem
        std::cout << "HEY.. SDL_Init HAS FAILED. SDL_ERROR: " << SDL_GetError() << std::endl; // Print error message if SDL initialization fails

    if (!(IMG_Init(IMG_INIT_PNG))) // Initialize SDL image subsystem for PNG images
        std::cout << "IMG_init has failed. Error: " << SDL_GetError() << std::endl; // Print error message if SDL image initialization fails

    RenderWindow window("GAME v0.3", 1000, 500); // Create window object with specified title and dimensions

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png"); // Load grass texture for the game
    
    // Create two platform entities with specified positions and the loaded grass texture
    Entity platform1(1,130, grassTexture); 
    Entity platform2(130,130, grassTexture);
       
 
    // Initialize game loop control variable
    bool gameRunning = true;

    // Initialize SDL event variable
    SDL_Event event;

    // Main game loop
    while (gameRunning)
    {
        // Handle events
        while (SDL_PollEvent(&event))
        {
            // Check if the event is a quit event
            if (event.type == SDL_QUIT)
                gameRunning = false; // Exit the game loop if quit event is detected
        }

        window.clear(); // Clear the window

        // Render platform entities to the window
        window.render(platform1);
        window.render(platform2);
        
        // Uncomment the following line to render platform3 (if needed)
        // window.render(platform3);

        window.display(); // Display the rendered content on the window

    }

    window.cleanUp(); // Clean up resources used by the window
    SDL_Quit(); // Quit SDL subsystems

    return 0; // Return 0 to indicate successful execution
}
