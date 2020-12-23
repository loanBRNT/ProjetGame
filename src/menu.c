#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "erreur.h"

#define LARGEUR_FEN 1280
#define HAUTEUR_FEN 720

void InteractionMenu(SDL_Window *window, SDL_Renderer *renderer){
	SDL_Texture *Img_fond = CreationMenu(window, renderer);
	SDL_RenderPresent(renderer);
	/*----------*/


	SDL_Delay(5000);
	

	/*----------*/
	SDL_DestroyTexture(Img_fond);
	DestructionFenAndRen(window, renderer);
}

SDL_Texture* CreationMenu(SDL_Window *window, SDL_Renderer *renderer){
	SDL_Surface* image_fond = NULL;
	SDL_Texture* texture = NULL;
	image_fond = SDL_LoadBMP("img/fond/fond_espace_note.bmp"); //On charge une image
	if (image_fond == NULL) {
		DestructionFenAndRen(window, renderer);
		RetourErreur("Impossible de charger l'image");
	}
	texture = SDL_CreateTextureFromSurface(renderer,image_fond); //On entre l'image dans une texture
	SDL_FreeSurface(image_fond);
	if (texture == NULL ){ 
		DestructionFenAndRen(window, renderer);
		RetourErreur("Impossible de creer la texture");
	}
	SDL_Rect cadre_menu;
	if (SDL_QueryTexture(texture, NULL, NULL, &cadre_menu.w, &cadre_menu.h) !=0){ //On met la texture dans un rectangle
		DestructionFenAndRen(window, renderer);
		RetourErreur("Impossible de charger la texture");
	}
	cadre_menu.x= (LARGEUR_FEN - cadre_menu.w)/2;
	cadre_menu.y= (HAUTEUR_FEN - cadre_menu.h)/2; //On centre la texture
	if (SDL_RenderCopy(renderer, texture, NULL, &cadre_menu) !=0){
		DestructionFenAndRen(window, renderer);
		RetourErreur("Impossible d'afficher la texture");
	}
	return texture;
}

