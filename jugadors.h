#ifndef _JUGADORS_H_
#define _JUGADORS_H_

typedef struct _node{
  Jugador_t jugador;
  struct _node *next;
  struct _node *prev;
} Node;

typedef struct{
  Node *first;
  Node *last;
  Node *pdi;
}LlistaJugadors;

LlistaJugadors LlistaJ_create();

// Afageix un jugador a la llista de Jugadors
int Jugador_insert(LlistaJugadors *, Jugador_t);

//Elimina la canción que se está reproduciendo de la playlist. Si quedan canciones,
//se empieza a reproducir la siguiente (o la primera si se llega al final).
int LlistaJ_remove(LlistaJugadors *);

//Pasa a el torn al següent jugador (o la primera si se llega al final).

int LlistaJ_next(LlistaJugadors *);

//Pasa el torn al jugador anterior (o la última si se llega al principio).

int LlistaJ_previous(LlistaJugadors *);

// Dona el jugador que esta jugant actualment
Jugador_t LlistaJ_get(LlistaJugadors *);

// Elimina las estructuras y libera memoria.
void LlistaJ_destroy(LlistaJugadors *);

#endif
