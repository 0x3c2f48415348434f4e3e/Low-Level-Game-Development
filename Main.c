#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include <stdbool.h>

#define WIDTH 600
#define HEIGHT 600

void initialise() {
	//Our window and surface
	SDL_Window* win = NULL;
	SDL_Surface* surface = NULL;

	//initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Could not initialised SDL: %s", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	//no need for else block, but who cares
	else {
		//to initialise window
		win = SDL_CreateWindow("Low Level Game programming", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		//CHECK IF ANY ERROR
		if (win == NULL) {
			printf("Eroor creating window: %s", SDL_GetError());
			exit(EXIT_FAILURE);
		}//no need for else block but who cares
		else {
			surface = SDL_GetWindowSurface(win);
			//check for error
			if (surface == NULL) {
				printf("Could not intialise surface: %s", SDL_GetError());
				exit(EXIT_FAILURE);
			}//no need for else block, but who cares
			else {
				//lets fill the surface
				SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 0xFF, 0XFF, 0XFF));
			}
		}
	}

	//update window
	SDL_UpdateWindowSurface(win);

	//check for inputs
	bool quit = false;
	SDL_Event event;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	//clean up
	SDL_DestroyWindow(win);
	//do not destroy surface as that is taken care for us
	SDL_Quit();

}

int main(int argc, char* argv[]) {
	initialise();
	return 0;
}