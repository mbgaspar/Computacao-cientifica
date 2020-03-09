/*
 * arvore.h
 *
 *  Created on: Nov 25, 2016
 *      Author: Renan Augusto Starke
 */

#ifndef SRC_ARVORE_ARVORE_H_
#define SRC_ARVORE_ARVORE_H_

#include "vertice.h"

typedef struct arvores arvore_t;

arvore_t* cria_arvore(int id);
vertice_t* arvore_adicionar_vertice_id(arvore_t *arvore, int id);
vertice_t* arvore_adicionar_vertice(arvore_t *arvore, vertice_t *vertice);
vertice_t* arvore_procura_vertice(arvore_t *arvore, int id);
vertice_t* arvore_get_raiz (arvore_t *arvore);
lista_enc_t *arvore_obter_vertices (arvore_t *arvore);

void arvore_exportar_grafo_dot(const char *filename, arvore_t *arvore);
void arvore_adiciona_filhos(arvore_t * arvore, vertice_t *vertice, int esq, int dir);
void arvore_set_raiz (arvore_t *arvore, vertice_t* vertice);
void libera_arvore(arvore_t *arvore);

void pre_ordem_recursivo(vertice_t* vertice, FILE* fp);
void pos_ordem_recursivo(vertice_t* vertice, FILE* fp);
void em_ordem_recursivo(vertice_t* vertice, FILE* fp);
void bfs(arvore_t* arvore, vertice_t* inicial);


#endif /* SRC_ARVORE_ARVORE_H_ */
