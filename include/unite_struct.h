#ifndef UNITE_STRUCT_H
#define UNITE_STRUCT_H

typedef struct Unitee Unitee;

struct Unitee
{
	char* Type_Unitee; //Type de Troupes : Guerrier, Archer...
	int Appartenance; //Joueur qui l'a contrôle
	int Points_de_Vie; //Defense du perso
	int Points_de_Degats; //Attaque du perso
	int Mouvement; //Nombre de case de mouvement
};



#endif