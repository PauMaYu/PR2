#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "dades.h"

Baraja Crear_Baraja(){
  Baraja baraja;  // també es podria inicialitzar aixi: Stack s = {0, NULL};
  baraja.mida = 0;
  baraja.last = NULL;
  return baraja;
}

int Coger_Carta(Baraja *baraja, Carta_t *c){
	if (baraja -> last == NULL){
    return 0;
  }
	* c = baraja -> last;

	Carta_t *aux;
	aux = baraja -> last -> next;
  baraja -> last = aux;
  free(aux);

  (baraja -> size)--;
  return 1;
}

int Baraja_Push(Baraja *b, Carta_t c){

    Carta_t * c_aux = (Carta_t * ) malloc(sizeof(Carta_t));
    if (c_aux == NULL) { //memory
      return 0;
    }
    c_aux -> numero = c.numero;
		c_aux -> color = c.color;
		c_aux -> tipus = c.tipus;
		c_aux -> propietari = c.propietari;

    c_aux -> next = b -> last;

    (b -> size)++; //no oblidar els parentesis
    b -> last = c_aux;
}

void Llenar_baraja(Baraja *baraja){

int i,j;
int index = 0;

	for (i=0; i<MAX_COLORS; i++){ // Bucles per assignar cartas del 0 al 9 amb diferents colors
		for (j=0; j<10; j++){
			Carta_t carta;
			carta.numero = j;
			carta.color = i;
			carta.tipus = NORMAL;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
			//baraja[index].seguent = index+1;
			//index++;
		}
	}
	for (i=0; i<MAX_COLORS; i++){ //Bucle per assignar cartas del 1 al 9 amb diferents colors
		for (j=1; j<10; j++){
			Carta_t carta;
			carta.numero = j;
			carta.color = i;
			carta.tipus = NORMAL;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
			//baraja[index].seguent = index+1;
			//index++;
		}
	}
	for (i=0; i<MAX_COLORS*2; i++){ // Carta especial no tirar
			Carta_t carta;
			carta.numero = SENSE_NUMERO;
			carta.color = i%MAX_COLORS; // per no repetir el bucle fem que la i valgui 2 cops cada color
			carta.tipus = SALTAR_TORN;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
			//baraja[index].seguent = index+1;
			//index++;
	}
	for (i=0; i<MAX_COLORS*2; i++){ // Carta especial canvi sentit
			Carta_t carta;
			carta.numero = SENSE_NUMERO;
			carta.color = i%MAX_COLORS; // per no repetir el bucle fem que la i valgui 2 cops cada color
			carta.tipus = CANVIAR_SENTIT;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
			//baraja[index].seguent = index+1;
			//index++;
	}
	for (i=0; i<MAX_COLORS*2; i++){ // Carta especial robar2
			Carta_t carta;
			carta.numero = SENSE_NUMERO;
			carta.color = i%MAX_COLORS; // per no repetir el bucle fem que la i valgui 2 cops cada color
			carta.tipus = ROBAR_2;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
	}
	for (i=0; i<MAX_COLORS; i++){ // Carta especial canvi color
			Carta_t carta;
			carta.numero = SENSE_NUMERO;
			carta.color = SENSE_COLOR;
			carta.tipus = COMODI_COLOR;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
	}
	for (i=0; i<MAX_COLORS; i++){ // Carta especial robar4
			Carta_t carta;
			carta.numero = SENSE_NUMERO;
			carta.color = SENSE_COLOR;
			carta.tipus = ROBAR_4;
			carta.propietari = PILA_ROBAR;
			Baraja_Push(baraja, carta);
	}
}

 //aqui es barregen les cartes 
void Barajar_baraja( Carta_t baraja[MAX_CARTES] ){

Carta_t tmp;
int i,j;
time_t t;
        t = time(NULL);
        srand(t);
        for(i = 0; i<MAX_CARTES ;i++){
                j = rand() % MAX_CARTES;
                tmp = baraja[i];
                baraja[i] = baraja[j];
                baraja[j] = tmp;
        }

		for(i = 0; i<MAX_CARTES ;i++){ //refem el index
			baraja[i].seguent = i+1;
		}
		baraja[MAX_CARTES-1].seguent = SENSE_SEGUENT;
}

void Repartir_cartes_inici(Carta_t baraja[MAX_CARTES], Partida_t *partida){

int i,j,index=0;

	for(i=0; i<partida->n_jugadors; i++){
		partida->ma[i].n_cartes = partida->Jugadors[i].n_cartes_def;
		partida->ma[i].primera_carta = index;

		for (j=0; j<partida->Jugadors[i].n_cartes_def; j++){
			baraja[index].propietari = i;
			index++;
		}
		baraja[index-1].seguent = SENSE_SEGUENT;
	}
	partida->descartades.primera_carta = index;
	partida->descartades.n_cartes = 1;
	baraja[index].propietari = PILA_DESCARTES;
	baraja[index].seguent = SENSE_SEGUENT;
	index++;

	partida->a_robar.primera_carta = index;
	partida->a_robar.n_cartes = MAX_CARTES - index;

}
