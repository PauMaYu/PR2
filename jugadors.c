#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dades.h"

//Inicializa las estructuras que consideréis necesarias.
LlistaJugadors Llista_create(){
  LlistaJugadors jugadors;
  jugadors.first = (Node *)malloc(sizeof(Node));
  jugadors.last = (Node *)malloc(sizeof(Node));
  if (jugadors.first == NULL){
    printf("Warning! Error on the creation of the LlistaJugadors!\n");
  } else {
      jugadors.pdi = jugadors.first;
      jugadors.pdi -> next = jugadors.last;
      jugadors.pdi -> prev = NULL;

      jugadors.last -> next = NULL;
      jugadors.last -> prev = jugadors.pdi;
  }
  return jugadors;
}

//Añade una canción a la playlist. Se añade a continuación de la canción que se esté
//reproduciendo actualmente, y se pasa a reproducir la nueva canción.
int Jugador_insert(LlistaJugadors *p, Jugador_t j){
  Node *n = (Node *)malloc(sizeof(Node));
  if ((n == NULL)){
    printf("Warning! Memory error while inserting a new Jugador.\n");
  } else {
    strcpy(n -> jugador.nom,j.nom);
    n -> jugador.huma = j.huma;
    n -> jugador.agressiu = j.agressiu;
    n -> jugador.n_cartes_def = j.n_cartes_def;

    n -> next = p -> pdi -> next;
    n -> prev = p -> pdi;

    p -> pdi -> next -> prev = n;
    p -> pdi -> next = n;

    p -> pdi = n;
  }
}

//Elimina la canción que se está reproduciendo de la playlist. Si quedan canciones,
//se empieza a reproducir la siguiente (o la primera si se llega al final).
int Llista_remove(LlistaJugadors *p){
  if (p -> first -> next == p -> last){
    return 0;
  }
  Node *tmp = p -> pdi;
  if (p -> pdi -> next == p -> last){
    p -> pdi -> prev -> next = p -> last;
    p -> last -> prev = p -> pdi -> prev;
    p -> pdi = p -> first -> next;
  } else {
    p -> pdi -> prev -> next = p -> pdi -> next;
    p -> pdi -> next -> prev = p -> pdi ->prev;
    p -> pdi = p -> pdi -> next;
  }
  free(tmp);

  return 1;
}

//Pasa a reproducir la siguiente canción de la playlist (o la primera si se llega al final).

int Llista_next(LlistaJugadors *p){
  if (p -> pdi -> next == p -> last){
    p -> pdi = p -> first -> next;
  } else {
    p -> pdi = p -> pdi -> next;
  }
  return 1;
}

//Pasa a reproducir la canción anterior de la playlist (o la última si se llega al principio).

int Llista_previous(LlistaJugadors *p){
  if (p -> pdi -> prev == p -> first){
    p -> pdi = p -> last -> prev;
  } else {
    p -> pdi = p -> pdi -> prev;
  }
  return 1;
}

int Llista_is_empty(LlistaJugadors p){
  return p.first -> next == p.last;
}
void Llista_go_first(LlistaJugadors *p){
    p -> last = p -> first;
}

//Devuelve la canción que se esté reproduciendo actualmente.
Jugador_t Llista_get(LlistaJugadors p){
  if (p.pdi == p.last){
  //    return NULL;
  }else{
    return p.pdi -> song;
  }
}

// Elimina las estructuras y libera memoria.
void Llista_destroy(LlistaJugadors *p){
  Llista_go_first(p);
  while (! Llista_is_empty(*p)){
    Llista_remove(p);
  }
  free(p -> first);
  free(p -> last);
  p -> first = p -> last = NULL;
}
