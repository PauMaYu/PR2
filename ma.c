#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "dades.h"

Ma Ma_create(){
  Ma ma;
  ma.first = (Node *)malloc(sizeof(Node));
  ma.last = (Node *)malloc(sizeof(Node));
  if (ma.first == NULL){
    printf("Warning! Error on the creation of the LlistaJugadors!\n");
  } else {
      ma.pdi = ma.first;
      ma.pdi -> next = ma.last;
      ma.pdi -> prev = NULL;

      ma.last -> next = NULL;
      ma.last -> prev = ma.pdi;
  }
  return ma;
}

//Añade una canción a la playlist. Se añade a continuación de la canción que se esté
//reproduciendo actualmente, y se pasa a reproducir la nueva canción.
int Carta_insert(Ma *p, Carta j){
  Node *n = (Node *)malloc(sizeof(Node));
  if ((n == NULL)){
    printf("Warning! Memory error while inserting a new Jugador.\n");
  } else {
    n -> carta = j;

    n -> next = p -> pdi -> next;
    n -> prev = p -> pdi;

    p -> pdi -> next -> prev = n;
    p -> pdi -> next = n;

    p -> pdi = n;
  }
}

//Elimina la canción que se está reproduciendo de la playlist. Si quedan canciones,
//se empieza a reproducir la siguiente (o la primera si se llega al final).
int Carta_remove(Ma *p){
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

int Carta_next(Ma *p){
  if (p -> pdi -> next == p -> last){
    p -> pdi = p -> first -> next;
  } else {
    p -> pdi = p -> pdi -> next;
  }
  return 1;
}

//Pasa a reproducir la canción anterior de la playlist (o la última si se llega al principio).

int Carta_previous(Ma *p){
  if (p -> pdi -> prev == p -> first){
    p -> pdi = p -> last -> prev;
  } else {
    p -> pdi = p -> pdi -> prev;
  }
  return 1;
}

int Ma_is_empty(Ma p){
  return p.first -> next == p.last;
}
void Ma_go_first(Ma *p){
    p -> last = p -> first;
}

//Devuelve la canción que se esté reproduciendo actualmente.
Carta_t Carta_get(Ma p){
  if (p.pdi == p.last){
  //    return NULL;
  }else{
    return p.pdi -> carta;
  }
}

// Elimina las estructuras y libera memoria.
void Ma_destroy(Ma *p){
  Llista_go_first(p);
  while (! Llista_is_empty(*p)){
    Llista_remove(p);
  }
  free(p -> first);
  free(p -> last);
  p -> first = p -> last = NULL;
}
