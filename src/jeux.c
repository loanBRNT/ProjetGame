#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "jeux.h"

#define GAIN_MINE_LV1 5
#define GAIN_MINE_LV2 7


int RecolteMinerai(int nb_ouvrier, int nb_mine_niv2){ //Fonction qui renvoie le gain en or à chaque début de tour
	int gain=0;
	for (int i=0; i<nb_mine_niv2; i++){
		for (int j=0; j<6 ; j++){
			if (nb_ouvrier > 0){
				nb_ouvrier = nb_ouvrier - 1;
				gain = gain + GAIN_MINE_LV1;
			} else {
				return gain;
			}
		}
	}
	gain = gain + (GAIN_MINE_LV1 * nb_ouvrier)
	return gain;
}