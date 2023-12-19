#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

#define WIDTH 600
#define HEIGHT 400

void initialise(void) {
	//window
	SDL_Window* mainWin;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		printf("Error initializing %s\n", SDL_GetError());
		exit(EXIT_FAILURE);
	}

	mainWin = SDL_CreateWindow("Low level Game programming", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0);

	//KEEP WINDOW UP
	while (1);

}

int main(void) {
	initialise();
	return 0;
}