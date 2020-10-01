#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

//#include <switch.h>

#include <iostream>
#include <vector>
#include <unistd.h>

#include "Main.h"
#include "RenderWindow.h"
#include "Entity.h"


int main(int argc, char* args []) {

    //  INITIALIZE SDL
	if(SDL_Init(SDL_INIT_VIDEO) > 0) {
		printf("SDL_Init failed! SDL_Error: %s\n", SDL_GetError());
	} else {
		printf("SDL_Init\n");
	}


    //  INITIALIZE SDL_Image
	if(!(IMG_Init(IMG_INIT_PNG))) {
		printf("IMG_Init failed! IMG_Error: %s\n", SDL_GetError());
	} else {
		printf("IMG_Init\n");
	}

    //  CREATE WINDOW FROM RenderWindow.h/cpp
	RenderWindow window("Game v1.0", 1280, 720);


	SDL_Texture* grassTexture = window.loadTexture("res\\gfx\\ground_grass_1.png");



	std::vector<Entity> entities = {	Entity(Vector2f(0, 0), grassTexture), 
										Entity(Vector2f(30, 0), grassTexture), 
										Entity(Vector2f(30, 30), grassTexture), 
										Entity(Vector2f(30, 60), grassTexture)
	};

	{
		Entity wilson(Vector2f(100, 50), grassTexture);

		entities.push_back(wilson);

	}

    //  MAIN GAME LOOP
	bool gameRunning = true;
	SDL_Event event;
	while(gameRunning) {
		while(SDL_PollEvent(&event)) {
			if(event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) { 
				printf("SDL_QUIT");
				gameRunning = false; 
			}
		}

		window.clear();

		for(Entity &e : entities) {
			window.render(e);
		}

		window.display();

	}

	window.cleanUp();
	SDL_Quit();
	return 0;

}
