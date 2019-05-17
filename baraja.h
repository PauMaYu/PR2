#ifndef _BARAJA_H_
#define _BARAJA_H_

typedef struct _node{
  Carta_t carta;
  struct _node *next;
} Node;

typedef struct{
  char Name[MAX_NOM]; //pot ser de robar o descartes
  int mida;
  Node *last;
}Baraja;

Baraja Crear_Baraja();

int Coger_Carta(Baraja *baraja, Carta_t *c);

int Baraja_Push(Baraja *b, Carta_t c);

void Llenar_baraja(Baraja *baraja);

void Barajar_baraja(Baraja *baraja);

void Repartir_cartes_inici(Carta_t baraja[MAX_CARTES], Partida_t *partida);

#endif
