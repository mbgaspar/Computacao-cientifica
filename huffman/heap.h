#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED

#include "arvore.h"

typedef struct heap heap_t;

heap_t* build_heap (int tam, int* vetor, int id);
void max_heapify(heap_t* heap, int i);
int heap_get_pai (heap_t* heap, int i);
int heap_get_esq (heap_t* heap, int i);
int heap_get_dir (heap_t* heap, int i);
int heap_get_vertice(heap_t* heap, int indice);
void heap_set_vertice(heap_t* heap, int indice, int dado);
void swap_heap (heap_t* heap, int indice, int maior);
void imprime_heap(heap_t* heap);
void libera_heap(heap_t* heap);
#endif // HEAP_H_INCLUDED
