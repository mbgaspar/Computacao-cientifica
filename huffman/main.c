/*
 ============================================================================
 Name        : grafos.c
 Author      :
 Version     :
 Copyright   : Renan Augusto Starke, todos os direitos reservados
 Description : grafos com lista encadeadas, Ansi-style
             : estruturas disponiveis:
             : pilha e fila
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "pilha.h"
#include "fila.h"
#include "arvore.h"
#include "vertice.h"
#include "heap.h"
#define SEM_FILHO -1


int main(void)
{

    int vetor[] = {16,7,9,8,14,10,3,2,4,1};

    heap_t* heap = build_heap(10,vetor,0);

    //imprime_heap(heap);

    arvore_t *arvore;
    vertice_t* vertice;
    vertice_t* inicial;
    fila_t *fila;
    pilha_t* pilha;

    arvore = cria_arvore(0);
    fila = cria_fila();
    pilha = cria_pilha();

    //Adiciona todos os vertices no grafo
    inicial = arvore_adicionar_vertice_id(arvore,16);
    arvore_set_raiz(arvore,inicial);

    vertice = arvore_adicionar_vertice_id(arvore, 14);


    vertice = arvore_adicionar_vertice_id(arvore, 10);


    vertice = arvore_adicionar_vertice_id(arvore, 8);


    vertice = arvore_adicionar_vertice_id(arvore, 7);


    vertice = arvore_adicionar_vertice_id(arvore, 9);


    vertice = arvore_adicionar_vertice_id(arvore,3);


    vertice = arvore_adicionar_vertice_id(arvore,2);


    vertice = arvore_adicionar_vertice_id(arvore,4);


    vertice = arvore_adicionar_vertice_id(arvore,1);

    arvore_adiciona_filhos(arvore,arvore_procura_vertice(arvore,16),14,10);
    arvore_adiciona_filhos(arvore,arvore_procura_vertice(arvore,14),8,7);
    arvore_adiciona_filhos(arvore,arvore_procura_vertice(arvore,8),2,4);
    arvore_adiciona_filhos(arvore,arvore_procura_vertice(arvore,7),1,SEM_FILHO);
    arvore_adiciona_filhos(arvore,arvore_procura_vertice(arvore,10),9,3);



    arvore_exportar_grafo_dot("arvore.dot", arvore);

    bfs(arvore,inicial);
contar_simbolos("msg.txt");
    libera_fila(fila);
    libera_pilha(pilha);
    libera_arvore(arvore);
    libera_heap(heap);

    return EXIT_SUCCESS;
}
