#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "erreur.h"

void RetourErreur(char* MessErreur){
	SDL_Log("ERREUR : %s > %s\n", MessErreur, SDL_GetError());
	SDL_Quit();
	exit(EXIT_FAILURE);
}

void DestructionFenAndRen(SDL_Window *window, SDL_Renderer *renderer){ 
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}