/*
 * vertice.c
 *
 *  Created on: Jul 5, 2016
 *      Author: Renan Augusto Starke
 */

#include <stdlib.h>
#include <stdio.h>

#include "vertice.h"
#include "lista_enc.h"

#define TRUE 1
#define FALSE 0

struct vertices {
	int id;                /*!< Identifica��o num�rica do v�rtice  */

	vertice_t *direita;    /*!< Filho � direta do v�rtice  */
	vertice_t *esquerda;   /*!< Filho � esquerda do v�rtice  */
	vertice_t* pai;        /*!< Pai do v�rtice. Null se ra�z da �rvore  */

	/* Dados associados ao vertice */
	int dist;
	int chave;
};

/**
  * @brief  Cria uma novo v�rtice
  * @param	id: identifica��o num�rica do v�rtice
  *
  * @retval vertice_t: ponteiro para um novo v�rtice
  */
vertice_t *cria_vertice(int id)
{
	vertice_t *p = NULL;

	p = malloc(sizeof(vertice_t));

	if (p == NULL) {
		perror("cria_vertice:");
		exit(EXIT_FAILURE);
	}

	p->id = id;
	p->direita = NULL;
	p->esquerda = NULL;
	p->pai = NULL;

	return p;
}

/**
  * @brief  Obt�m o identificador de um v�rtice
  * @param	vertice: ponteiro de um v�rtice
  *
  * @retval int: identificador num�rico do v�rtice
  */
int vertice_get_id(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_obter_id: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->id;
}

/**
  * @brief  Configura o pai de um v�rtice
  * @param	vertice: ponteiro de um v�rtice
  * @param  pai: ponteiro do v�rtice pai
  *
  * @retval Nenhum
  */
void vertice_set_pai(vertice_t *vertice, vertice_t *pai) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_pai: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->pai = pai;
}

/**
  * @brief  Configura o filho � esquerda de um v�rtice
  * @param	vertice: ponteiro de um v�rtice
  * @param  esq: ponteiro do v�rtice � esquerda
  *
  * @retval Nenhum
  */
void vertice_set_esq(vertice_t *vertice, vertice_t *esq) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->esquerda = esq;
}

/**
  * @brief  Configura o filho � direita de um v�rtice
  * @param	vertice: ponteiro de um v�rtice
  * @param  dir: ponteiro do v�rtice � direita
  *
  * @retval Nenhum
  */
void vertice_set_dir(vertice_t *vertice, vertice_t *dir) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->direita = dir;
}

/**
  * @brief  Obt�m o v�rtice filho � esquerda
  * @param	vertice: ponteiro de um v�rtice.
  *
  * @retval vertice_t: ponteiro do v�rtice � esquerda. NULL se n�o h� nenhum filho
  */
vertice_t* vertice_get_esq(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_esq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->esquerda;
}

/**
  * @brief  Obt�m o v�rtice filho � direita
  * @param	vertice: ponteiro de um v�rtice.
  *
  * @retval vertice_t: ponteiro do v�rtice � direita.  NULL se n�o h� nenhum filho
  */
vertice_t* vertice_get_dir(vertice_t *vertice) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_get_dir: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->direita;
}

/**
  * @brief  Obt�m o dado "chave" associado � um v�rtice
  * @param	vertice: ponteiro de um v�rtice.
  *
  * @retval int: dado inteiro associado
  */
int vertice_get_chave (vertice_t * vertice){


	if (vertice == NULL){
			fprintf(stderr, "vertice_get_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->chave;
}

/**
  * @brief  Configura o dado "chave" associado � um v�rtice
  * @param	vertice: ponteiro de um v�rtice.
  * @param  chave: chave num�rica associada � um v�rtice
  *
  * @retval Nenhum
  */
void vertice_set_chave (vertice_t * vertice, int chave){


	if (vertice == NULL){
			fprintf(stderr, "vertice_set_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->chave = chave;
}

/**
  * @brief  Obt�m o pai de um v�rtice
  * @param	vertice: ponteiro de um v�rtice.
  *
  * @retval vertice_t: ponteiro que representa o pai
  */
vertice_t *vertice_get_pai(vertice_t *vertice){

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_freq: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	return vertice->pai;
}
/**
  * @brief  Retorna se um v�rtice � uma folha.
  * @param	vertice: ponteiro de um v�rtice.
  *
  * @retval int: 0 se n�o for folha, > 0 se for uma folha
  */
int vertice_eh_folha(vertice_t *vertice){

	if (vertice == NULL){
		fprintf(stderr, "eh_folha: vertice invalido\n");
		exit(EXIT_FAILURE);
	}

	if (vertice->direita == NULL && vertice->esquerda == NULL)
		return TRUE;

	return FALSE;

}


void vertice_set_dist(vertice_t *vertice, int dist) {

	if (vertice == NULL){
			fprintf(stderr, "vertice_set_dist: vertice invalido\n");
			exit(EXIT_FAILURE);
	}

	vertice->dist = dist;
}

int vertice_get_dist(vertice_t *vertice)
{
	if (vertice == NULL)
	{
		fprintf(stderr, "vertice_get_dist: vertice invalido!\n");
		exit(EXIT_FAILURE);
	}

	return vertice->dist;
}
