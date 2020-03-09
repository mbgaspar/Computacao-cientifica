#include <stdio.h>
#include <stdlib.h>

#include "no.h"

struct nos{
    void* dados;     /*!< Refer�ncia do dado respectiva ao n� da lista encadeada. */
    no_t *proximo;   /*!< Refer�ncia do pr�ximo elemento da lista encadeada. */
    no_t *anterior;  /*!< Refer�ncia do elemento anterior da lista encadeada. */
};

/**
  * @brief  Cria um novo n� de lista encadeada.
  * @param	dado: ponteiro gen�rico para qualquer tipo de dado.
  *
  * @retval no_t: ponteiro do tipo n� contendo a refer�ncia do dado.
  */
no_t *cria_no(void *dado)
{
    no_t *p = malloc(sizeof(no_t));

    if (p == NULL){
        perror("cria_no:");
        exit(EXIT_FAILURE);
    }

    p->dados = dado;
    p->proximo = NULL;
    p->anterior = NULL;

    return p;
}

/**
  * @brief  Faz o encadeamento entre dois n�s de encadeados.
  * @param	fonte: ponteiro da fonte entre a liga��o.
  * @param  destino: ponteiro do destino entre a liga��o.
  *
  * @retval Nenhum.
  */
void liga_nos (no_t *fonte, no_t *destino)
{
    if (fonte == NULL || destino == NULL){
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    fonte->proximo = destino;
    destino->anterior = fonte;
}

/**
  * @brief  Remove encadeamento completo.
  * @param	no: n� de lista que se deseja remover liga��o.
  *
  * @retval Nenhum.
  */
void desliga_no (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
    no->anterior = NULL;
}


/**
  * @brief  Remove encadeamento: apenas n� anterior.
  * @param	no: n� de lista que se deseja remover liga��o.
  *
  * @retval Nenhum.
  */
void desliga_no_anterior (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->anterior = NULL;
}

/**
  * @brief  Remove encadeamento: apenas n� sucessor.
  * @param	no: n� de lista que se deseja remover liga��o.
  *
  * @retval Nenhum.
  */
void desliga_no_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    no->proximo = NULL;
}

/**
  * @brief  Obt�m a refer�ncia do dado pertencente ao n� de lista encadeada.
  * @param	no: n� de lista que se deseja obter o dado.
  *
  * @retval void *: dado referenciado pelo n� encadeado.
  */
void *obter_dado (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->dados;
}

/**
  * @brief  Obt�m a pr�xima refer�ncia encadeada.
  * @param	no: n� de lista que se deseja obter o pr�ximo elemento.
  *
  * @retval no_t *: onteiro do pr�ximo elemento da lista. NULL se final de lista.
  */
no_t *obtem_proximo (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->proximo;
}

/**
  * @brief  Obt�m a refer�ncia encadeada anterior.
  * @param	no: n� de lista que se deseja obter o elemento anterior.
  *
  * @retval no_t *: ponteiro do elemento anterior da lista. NULL se final de lista.
  */
no_t *obtem_anterior (no_t *no)
{
    if (no == NULL) {
        fprintf(stderr,"liga_nos: ponteiros invalidos");
        exit(EXIT_FAILURE);
    }

    return no->anterior;
}
