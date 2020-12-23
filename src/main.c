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
    SDL_Window *ecran = NULL;
    SDL_Renderer *rendEcran = NULL;
    SDL_Surface *icone = NULL;


    if (SDL_Init(SDL_INIT_EVERYTHING) !=0){ //Initialisation de la SDL
    	RetourErreur("Initialisation de la SDL echouee");
    }

    // Verif SDL
    SDL_VERSION(&nb);
    printf("Bienvenue sur la DSL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);


// creation fenetre
    CreationFenAndRenAndIco(ecran,rendEcran,icone);

/*----------------------------------------------*/
    InteractionMenu(ecran, rendEcran);
/*----------------------------------------------*/

    SDL_Quit(); //Sortie de la SDL
    return EXIT_SUCCESS;
}
 