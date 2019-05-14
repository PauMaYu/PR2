#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "dades.h"

#define CALMADO "CALMADO"

int LlegirParams(char *fusr, char *fbots, Partida_t *partida){

char line[MAX_NOM];
int nbots, ibot;

	FILE *f;
	f = fopen(fusr, "r");
	if (f == NULL){
		perror ("No existe el config");
		exit (1);
	}
	fgets(partida->Jugadors[0].nom,MAX_NOM,f);
	partida->Jugadors[0].nom[strlen(partida->Jugadors[0].nom)-1]=0; // quitar newline
	partida->Jugadors[0].huma = true;
	partida->Jugadors[0].agressiu = false;
	partida->Jugadors[0].n_cartes_def = 7;
	fclose (f);

	f = fopen(fbots, "r");
	if (f == NULL){
		perror ("No existe el config");
		exit (1);
	}
	fgets(line,MAX_NOM,f);
	sscanf(line,"%d",&nbots);

	for(ibot=1;ibot<=nbots;ibot++){
		partida->Jugadors[ibot].huma = false;
		fgets(partida->Jugadors[ibot].nom,MAX_NOM,f);
		fgets(line,MAX_NOM,f);
		line[strlen(line)-1]=0; // quitar newline
		if (strcasecmp(CALMADO,line)==0) partida->Jugadors[ibot].agressiu=false;
		else partida->Jugadors[ibot].agressiu=true;

		fgets(line,MAX_NOM,f);
		sscanf(line,"%d",&partida->Jugadors[ibot].n_cartes_def);
	}
	fclose (f);

	partida->n_jugadors = nbots + 1;
}

