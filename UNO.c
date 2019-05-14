#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dades.h"
#include "baraja.h"
#include "lectura.h"

Carta_t baraja[MAX_CARTES];
char *Colors[MAX_COLORS+1] = {"VERMELL","GROC","VERD","BLAU","s/c"};
char *Especial[MAX_ESPECIAL] = {"NORMAL","SALTAR_TORN","CANVIAR_SENTIT","ROBAR_2","COMODI_COLOR","ROBAR_4"};


Partida_t Partida;

void PintarBaraja(){
int i;
	for (i=0; i<MAX_CARTES; i++){
		printf("i=%d color=%s numero=%d tipus= %s propietari=%d seguent=%d\n", i, Colors[baraja[i].color], baraja[i].numero, Especial[baraja[i].tipus], baraja[i].propietari, baraja[i].seguent);
	}
}

void main (int argn, char * argv[]){
	if (argn<3) {
		printf("Error fitxers...\n");
		exit;
	} else {

	LlegirParams(argv[1],argv[2],&Partida);

	Crear_baraja(baraja);
	Barajar_baraja(baraja); // Barrejar 4 vegades
	Barajar_baraja(baraja);
	Barajar_baraja(baraja);
	Barajar_baraja(baraja);
	Repartir_cartes(baraja, &Partida);
	PintarBaraja();

	/*
	Comença la Partida
	*/

	}
}
