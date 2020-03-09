/*
 * arvore.c
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "vertice.h"
#include "arvore.h"
#include "fila.h"
#include "pilha.h"

#define INFINITO INT_MAX
#define FALSE 0
#define TRUE 1
//#define DEBUG

struct arvores
{
    int id;                /*!< Identificação numérica da árvore */
    vertice_t *raiz;       /*!< Ponteiro para o vértice raiz  */
    lista_enc_t *vertices; /*!< Lista encadeada de vértices  */
};


/**
  * @brief  Cria uma árvore. Grau depende do vértice.
  * @param	id: identificação numérica da árvore.
  *
  * @retval arvore_t: ponteiro para uma nova árvore.
  */
arvore_t *cria_arvore(int id)
{
    arvore_t *p = NULL;

    p = (arvore_t*) malloc(sizeof(arvore_t));

    if (p == NULL)
    {
        perror("cria_grafo:");
        exit(EXIT_FAILURE);
    }

    p->id = id;
    p->vertices = cria_lista_enc();

    return p;
}

/**
  * @brief  Adiciona um vértice na árvore. Essa função cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificação numérica do vértice.
  *
  * @retval vertice_t: ponteiro do novo vértice criado e adicionado na árvore.
  */
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id)
{
    vertice_t *vertice;
    no_t *no;

#ifdef DEBUG
    printf("grafo_adicionar_vertice: %d\n", id);
#endif

    if (arvore == NULL)
    {
        fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
        exit(EXIT_FAILURE);
    }

    if (arvore_procura_vertice(arvore, id) != NULL)
    {
        fprintf(stderr,"grafo_adicionar_vertice: vertice duplicado!\n");
        exit(EXIT_FAILURE);
    }

    vertice = cria_vertice(id);
    no = cria_no(vertice);

    add_cauda(arvore->vertices, no);

    return vertice;
}


/**
  * @brief  Adiciona um vértice criado na árvore. Essa função NÃO cria um novo vértice.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	vertice: ponteiro válido de um vértice.
  *
  * @retval vertice_t: ponteiro do vértice adicionado na árvore.
  */
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice)
{
    no_t *no;

#ifdef DEBUG
    printf("grafo_adicionar_vertice: %d\n", id);
#endif

    if (arvore == NULL)
    {
        fprintf(stderr,"grafo_adicionar_vertice: grafo invalido!");
        exit(EXIT_FAILURE);
    }

    no = cria_no(vertice);

    add_cauda(arvore->vertices, no);

    return vertice;
}

/**
  * @brief  Procura um vértice com identificador específico na árvore.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param	id: identificador do vértice procurado.
  *
  * @retval vertice_t: NULL se vértice não pertencer a árvore. Um um ponteiro válido caso contrário.
  */
vertice_t* arvore_procura_vertice(arvore_t *arvore, int id)
{
    no_t *no_lista;
    vertice_t *vertice;
    int meu_id;

    if (arvore == NULL)
    {
        fprintf(stderr,"procura_vertice: grafo invalido!");
        exit(EXIT_FAILURE);
    }

    if (lista_vazia(arvore->vertices) == TRUE)
        return FALSE;

    no_lista = obter_cabeca(arvore->vertices);

    while (no_lista)
    {
        //obtem o endereco da lista
        vertice = obter_dado(no_lista);

        //obterm o id do vertice
        meu_id = vertice_get_id(vertice);

        if (meu_id == id)
        {
            return vertice;
        }

        no_lista = obtem_proximo(no_lista);
    }

    return NULL;
}


/**
  * @brief  Configura os filhos de um vértices PERTENCENTES à um árvore por identificador.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  vertice: ponteiro de um vértice à ser configurado.
  * @param	esq: identificador numérico do vértice à esquerda.
  * @param	dir: identificador numérico do vértice à direita.
  *
  * @retval Nenhum
  */
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir)
{
    vertice_t *esquerda;
    vertice_t *direita;

    if (arvore == NULL)
    {
        fprintf(stderr,"arvore_adiciona_filhos: arvore invalida!");
        exit(EXIT_FAILURE);
    }

    if (esq != -1)
    {
        esquerda = arvore_procura_vertice(arvore, esq);
        vertice_set_pai(esquerda, vertice);
        vertice_set_esq(vertice, esquerda);
    }

    if (dir != -1)
    {
        direita = arvore_procura_vertice(arvore, dir);
        vertice_set_pai(direita, vertice);
        vertice_set_dir(vertice, direita);
    }
}

/**
  * @brief  Exporta em formato DOT uma árvore.
  * @param  filename: nome do arquivo DOT gerado.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  */
void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore)
{
    FILE* file;



    if (filename == NULL || arvore == NULL)
    {
        fprintf(stderr, "exportar_arvore_dot: ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }


    file = fopen(filename, "w");

    if (file == NULL)
    {
        perror("exportar_arvore_dot:");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "graph {\n");

    em_ordem_recursivo(arvore->raiz, file);

    fprintf(file," }\n");
    fclose(file);
}

/**
  * @brief  Libera memória dinâmica de uma uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval Nenhum
  */
void libera_arvore(arvore_t* arvore)
{

    if (arvore == NULL)
    {
        fprintf(stderr, "libera_arvore: arvore invalida\n");
        exit(EXIT_FAILURE);
    }

    no_t* meu_no = obter_cabeca(arvore->vertices);

    while(meu_no)
    {
        vertice_t* dado = obter_dado(meu_no);
        no_t* proximo = obtem_proximo(meu_no);
        free(dado);
        free(meu_no);
        meu_no= proximo;
    }
    free(arvore->vertices);
    free(arvore);
}

/**
  * @brief  Configura a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
  * @param  vertice: ponteiro válido de um vértice
  *
  * @retval Nenhum
  */
void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice)
{
    if (arvore == NULL)
    {
        fprintf(stderr, "arvore_set_raiz: arvore invalida\n");
        exit(EXIT_FAILURE);
    }

    arvore->raiz = vertice;

}

/**
  * @brief  Obtém a raiz de uma árvore.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval vertice_t: ponteiro do vértice raiz.
  */
vertice_t* arvore_get_raiz (arvore_t *arvore)
{
    if (arvore == NULL)
    {
        fprintf(stderr, "arvore_get_raiz: arvore invalida\n");
        exit(EXIT_FAILURE);
    }

    return arvore->raiz;
}

/**
  * @brief  Obtém a lista encadeada de vértices.
  * @param  arvore: ponteiro válido de uma árvore.
    *
  * @retval lista_enc_t: ponteiro da lista encadeada contendo todos os vértices da árvore.
  */
lista_enc_t *arvore_obter_vertices (arvore_t *arvore)
{

    if (arvore == NULL)
    {
        fprintf(stderr, "arvore_obter_vertices: arvore invalida\n");
        exit(EXIT_FAILURE);
    }


    return arvore->vertices;
}

void pre_ordem_recursivo(vertice_t* vertice, FILE* fp)

{

    if(vertice==NULL)
    {
        return;
    }

    if(vertice_get_esq(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_esq(vertice)),1);

    }
    if(vertice_get_dir(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_dir(vertice)),1);

    }
    pre_ordem_recursivo(vertice_get_esq(vertice),fp);
    pre_ordem_recursivo(vertice_get_dir(vertice),fp);
}

void pos_ordem_recursivo(vertice_t* vertice, FILE* fp)

{

    if(vertice==NULL)
    {
        return;
    }

    pos_ordem_recursivo(vertice_get_esq(vertice),fp);
    pos_ordem_recursivo(vertice_get_dir(vertice),fp);

    if(vertice_get_esq(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_esq(vertice)),1);

    }
    if(vertice_get_dir(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_dir(vertice)),1);

    }
}

void em_ordem_recursivo(vertice_t* vertice, FILE* fp)
{
    if(vertice==NULL)
    {
        return;
    }

    em_ordem_recursivo(vertice_get_esq(vertice),fp);

    if(vertice_get_esq(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_esq(vertice)),1);

    }
    if(vertice_get_dir(vertice))
    {
        fprintf(fp, "\t%d -- %d [label = %d]\n", vertice_get_id(vertice), vertice_get_id(vertice_get_dir(vertice)),1);

    }

    em_ordem_recursivo(vertice_get_dir(vertice),fp);

}


/**
 * @brief  Busca em largura
 * @param	grafo: ponteiro do grafo que se deseja executar a busca
 * @param  inicial: ponteiro do vértice inicial (fonte) da busca
 *
 * @retval Nenhum: Vértices são marcados internamente
 */
void bfs(arvore_t* arvore, vertice_t* inicial)
{
    if (arvore == NULL)
    {

        fprintf(stderr, "bfs: arvore invalida\n");
        exit(EXIT_FAILURE);
    }
    if (inicial == NULL)
    {

        fprintf(stderr, "bfs: vertice invalido\n");
        exit(EXIT_FAILURE);
    }

    fila_t* Q = cria_fila();
    no_t* no_vertice = obter_cabeca(arvore->vertices);

    while(no_vertice)
    {
        vertice_t* meu_vertice = obter_dado(no_vertice);
        vertice_set_dist(meu_vertice, INFINITO);
        vertice_set_pai(meu_vertice, NULL);
        no_vertice = obtem_proximo(no_vertice);

    }
    vertice_set_dist(inicial, 0);
    enqueue(inicial,Q);



    printf("\nIniciando bfs busca em largura...\n");


    enqueue(inicial, Q);
    ///Busca
    printf(" vertice inicial: %d\n", vertice_get_id(inicial));
    while (!fila_vazia(Q))
    {
        vertice_t* u = dequeue(Q);
        if (vertice_get_esq(u) && vertice_get_dist(vertice_get_esq(u))==INFINITO)
        {
            vertice_set_dist(vertice_get_esq(u),vertice_get_dist(u)+1);
            vertice_set_pai(vertice_get_esq(u),u);
            enqueue(vertice_get_esq(u), Q);
            printf("visitado vertice: %d \t Distancia: %d \t Pai: %d\n",vertice_get_id(vertice_get_esq(u)),vertice_get_dist(vertice_get_esq(u)),vertice_get_id(u));

        }


        if (vertice_get_dir(u) && vertice_get_dist(vertice_get_dir(u))==INFINITO)
        {
            vertice_set_dist(vertice_get_dir(u),vertice_get_dist(u)+1);
            vertice_set_pai(vertice_get_dir(u),u);
            enqueue(vertice_get_dir(u), Q);
            printf("visitado vertice: %d \t Distancia: %d \t Pai: %d\n",vertice_get_id(vertice_get_dir(u)),vertice_get_dist(vertice_get_dir(u)),vertice_get_id(u));
        }


    }
}
