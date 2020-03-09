#include <stdio.h>
#include <stdlib.h>

int main()
{
    int grau,i;
    double *a,x,p;
    printf("Entre com o grau do polinomio: ");
    scanf("%d",&grau);
    a= (double*)malloc(sizeof(double)*grau);
    printf("\nEntre com os coef. do polin. iniciando por a0: \n");

    for(i=0;i<grau+1;i++)
    {
        printf("a[%d]: ", i);
         scanf("%lf", &a[i]);

    }
    for(i=0;i<=grau;i++)
    {
         printf("a[%d]= %lf ", i, a[i]);

    }

    printf("\nEntre com o valor de x: \n");
    scanf("%lf", &x);

    p= a[grau];

    for(i= grau-1; i>=0; i--)
    {
        p= p*x + a[i];
    }

    printf("\np(%lf)= %lf\n", x, p);
    return 0;
}
