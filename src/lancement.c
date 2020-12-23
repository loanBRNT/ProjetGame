#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "lancement.h"
#include "erreur.h"

#define LARGEUR_FEN 1280
#define HAUTEUR_FEN 720


FILE* CreationSauvegarde(int Emplacement, char* NomSauvegarde, char CouleurJ1){
	char nombre='0';
	int case_h=0, case_l=0;
	FILE* fichier_sauvegarde = NULL;
	FILE* Base_map_1= NULL;
	switch (Emplacement){
		case 1:
			fichier_sauvegarde = fopen("sauv/sauvegarde_1.txt","w+");
			break;
		case 2:
			fichier_sauvegarde = fopen("sauv/sauvegarde_2.txt","w+");
			break;
		case 3:
			fichier_sauvegarde = fopen("sauv/sauvegarde_3.txt","w+");
			break;
		default:
			RetourErreur("Impossible d'ouvrir l'Emplacement de sauvegarde : emplacement inexistant");
			break;
	}
	Base_map_1 = fopen("sauv/map_1.txt","r");
	if ((Base_map_1 != NULL) && (fichier_sauvegarde != NULL)){
		fscanf(Base_map_1,"%d %d", &case_l, &case_h); //Recup du nombre de case longueur et largeur
		fprintf(fichier_sauvegarde, "%s\n%d %d", NomSauvegarde, case_l, case_h); //Affichage de Nom de la Sauv + case
		while ((nombre=fgetc(Base_map_1)) != EOF) {
			fprintf(fichier_sauvegarde, "%c", nombre); //Initialisation du plateau de jeux
		} 
	}
	else {
		printf("Impossible d'ouvrir les fichiers de sauvegarde");
	}
	fclose(Base_map_1);
	fprintf(fichier_sauvegarde, "J1 %s\n0\n2\n25\nJ2\n0\n2\n25\n", CouleurJ1); //On ecris les valeurs par defauts d'unite, d'ouvrier et d'argent
	fclose(fichier_sauvegarde);
	return fichier_sauvegarde;
}