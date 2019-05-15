#ifndef _MA_H_
#define _MA_H_

typedef struct _node{
  Carta_t carta;
  struct _node *next;
  struct _node *prev;
} Node;

typedef struct{
  Node *first;
  Node *last;
  Node *pdi;
}Ma;

Ma Ma_create();

// Afageix un jugador a la llista de Jugadors
int Carta_insert(Ma *, Carta_t);

//Elimina la canción que se está reproduciendo de la playlist. Si quedan canciones,
//se empieza a reproducir la siguiente (o la primera si se llega al final).
int Carta_remove(Ma *);

//Pasa a el torn al següent jugador (o la primera si se llega al final).

int Carta_next(Ma *);

//Pasa el torn al jugador anterior (o la última si se llega al principio).

int Carta_previous(Ma *);

// Dona el jugador que esta jugant actualment
Carta_t Carta_get(Ma *);

// Elimina las estructuras y libera memoria.
void Ma_destroy(Ma *);

#endif
