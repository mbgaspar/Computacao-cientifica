#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"
#include "heap.h"
//#define DEBUG

struct heap
{
    int id;
    int tam;
    int *vetor;
};

heap_t* build_heap (int tam, int* vetor, int id)
{
    int i;
    heap_t* h = (heap_t*)malloc(sizeof(heap_t));

    if (h == NULL)
    {
        fprintf(stderr, "Erro alocando dados em build_heap!\n");
        exit(EXIT_FAILURE);
    }
    h-> tam = tam;
    h-> vetor = vetor;
    h-> id = id;

    for (i=0 ; i< h->tam/2 -1; i++)
    {
        max_heapify(h, i);

    }

#ifdef DEBUG

    printf("Heap \n");
    for (i = 0; i < h->tam; i++)
    {
        printf(" %d \t", h->vetor[i]);
    }

#endif

    return h;
}



void max_heapify(heap_t* heap, int i)
{

    if(heap == NULL)
    {
        fprintf(stderr, "max_heapify: heap inválido");
        exit(EXIT_FAILURE);
    }

    int e = heap_get_esq(heap,i);
    int d = heap_get_dir(heap,i);
    int maior;

    if (e< heap->tam && heap_get_vertice(heap, e)> heap_get_vertice(heap, i) )
    {
        maior = e;
    }
    else
    {
        maior = i;
    }

    if (d< heap->tam && heap_get_vertice(heap, d)> heap_get_vertice(heap, maior) )
    {
        maior = d;
    }


    if(maior!=i)
    {
        swap_heap(heap,i,maior);
        max_heapify(heap,maior);
    }


}

int heap_get_pai (heap_t* heap, int i)
{
    if(heap == NULL)
    {
        fprintf(stderr, "heap_get_pai: heap inválido");
        exit(EXIT_FAILURE);
    }

    return (i-1)/2;
}

int heap_get_esq (heap_t* heap, int i)
{
    if(heap == NULL)
    {
        fprintf(stderr, "heap_get_esq: heap inválido");
        exit(EXIT_FAILURE);
    }

    return (2*i)+1;
}

int heap_get_dir (heap_t* heap, int i)
{
    if(heap == NULL)
    {
        fprintf(stderr, "heap_get_dir: heap inválido");
        exit(EXIT_FAILURE);
    }

    return (2*i)+2;
}

int heap_get_vertice(heap_t* heap, int indice)
{
    if(heap == NULL)
    {
        fprintf(stderr, "heap_get_dir: heap inválido");
        exit(EXIT_FAILURE);
    }

    return heap-> vetor[indice];
}

void heap_set_vertice(heap_t* heap, int indice, int dado)
{
    if(heap == NULL)
    {
        fprintf(stderr, "heap_set_vertice: heap inválido");
        exit(EXIT_FAILURE);
    }

    heap-> vetor[indice]=dado;
}

void swap_heap (heap_t* heap, int indice, int maior)
{
    if(heap == NULL)
    {
        fprintf(stderr, "swap: heap inválido");
        exit(EXIT_FAILURE);
    }

    int temp;
    temp = heap_get_vertice(heap, indice);
    heap_set_vertice(heap, indice, heap_get_vertice(heap,maior));
    heap_set_vertice(heap, maior, temp);

}

void imprime_heap(heap_t* heap)
{
    if(heap == NULL)
    {
        fprintf(stderr, "imrime_heap: heap inválido");
        exit(EXIT_FAILURE);
    }

    int i;
    for(i=0; i<heap->tam; i++)
    {
        printf("%d \t", heap_get_vertice(heap, i));
    }

}

void libera_heap(heap_t* heap)
{
    free(heap);
}
