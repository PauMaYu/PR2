#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dades.h"
#include "baraja.h"
#include "lectura.h"
#include "ma.h"
#include "jugadors.h"

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

void GenerarJugadors(LlistaJugadors *j, char jugadors[50]){
	//Aqui es llegeix el document de jugadors i es posa dins de la Llista

	// també posem el nostre jugador
}

void Inicializa_baraja(Baraja *b_robar){
	// Aqui s'inicialitza la baralla, s'omple, es barreja...
	/*
	Això és el que estava escrit a baix
	Crear_baraja(baraja);
	Barajar_baraja(baraja); // Barrejar 4 vegades
	Barajar_baraja(baraja);
	Barajar_baraja(baraja);
	Barajar_baraja(baraja);
	Repartir_cartes(baraja, &Partida);
	PintarBaraja();
	*/
}

void main (int argn, char * argv[]){
	if (argn<3) {
		printf("Error fitxers...\n");
		exit;
	} else {

	LlistaJugadors llista_j;
	GenerarJugadors(&llista_j, argv[1]);

	Baraja b_robar;
	Inicializa_baraja(&b_robar);

	LlegirParams(argv[1],argv[2],&Partida);

22

	}

/*int opcio;

	printf("UNO\n\n");
	printf("1.Jugar\n");
	printf("2.Mostrar estadisticas\n");
	printf("3.Salir\n\n");

        do {
        printf("\nOpcion: ");
        scanf("%d", &opcio);

	switch(opcio){
	printf("UNO")
		case 1:
			// bla bla
			break;

		case 2:
			// bla bla
			break;

		case 3:
			break;

	 default : printf("Opcion erronia\n");
        }
    }while (opcion != 3);
	*/
}
