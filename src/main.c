#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "erreur.h"
#include "jeux.h"
#include "animation.h"
#include "lancement.h"
#include "chargement.h"



#define LARGEUR_FEN 1280
#define HAUTEUR_FEN 720

/* 
    Commande de compilation avec gcc :
    gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
    gcc src/* -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
*/ 

int main(int argc, char **argv)
{
    SDL_version nb;
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;


    if (SDL_Init(SDL_INIT_EVERYTHING) !=0){ //Initialisation de la SDL
    	RetourErreur("Initialisation de la SDL echouee");
    }

    // Verif SDL
    SDL_VERSION(&nb);
    printf("Bienvenue sur la DSL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);

    if (SDL_CreateWindowAndRenderer(LARGEUR_FEN, HAUTEUR_FEN, 0, &window, &renderer) !=0){
    	RetourErreur("Creation de la Fentre/rendu echouee");
    }
/*----------------------------------------------*/
    InteractionMenu(window, renderer);
/*----------------------------------------------*/

    SDL_Quit(); //Sortie de la SDL
    return EXIT_SUCCESS;
}
 