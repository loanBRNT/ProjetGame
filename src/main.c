#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/* 
    Commande de compilation avec gcc :
    gcc src/main.c -o bin/prog -I include -L lib -lmingw32 -lSDL2main -lSDL2
*/ 

int main(int argc, char **argv)
{
    SDL_version nb;
    SDL_VERSION(&nb);

    printf("Bienvenue sur la DSL %d.%d.%d !\n", nb.major, nb.minor, nb.patch);
    return 0;
}
 