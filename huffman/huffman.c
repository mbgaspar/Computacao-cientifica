#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "huffman.h"


struct simbolos
{
    char simb;
    int freq;

};

simbolos_t* cria_tabela (void)
{
    simbolos_t* s = (simbolos_t*)malloc(sizeof(simbolos_t)*256);
    if (s == NULL)
    {
        fprintf(stderr, "Erro alocando dados em cria_tabela!\n");
        exit(EXIT_FAILURE);
    }

    s->freq = 0;
    s->simb = '\0';

    return s;
}


void contar_simbolos(const char *filename)
{
    FILE* fp;
    char msg[100];
    simbolos_t* simbolos = cria_tabela();
    int i,n,j,count=0;

    if (filename == NULL)
    {
        fprintf(stderr, "contar_simbolos: ponteiros invalidos\n");
        exit(EXIT_FAILURE);
    }

    fp = fopen(filename, "r");
    n= fread(msg, sizeof(char),100,fp);
 printf("%d",n);

 simbolos[0].simb = msg[0];

    for(i=0; i<n; i++)
    {
        for(j=1; j<n; j++)
        {

        }
    }

 for(i=0; i<n; i++)
 {
     printf("\n%c", simbolos[i].simb);
 }






}
