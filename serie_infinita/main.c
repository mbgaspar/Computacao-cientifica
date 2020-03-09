#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float fn=0,i;

   double et ,vr=(M_PI*M_PI*M_PI*M_PI)/90;

    for(i=1; i<=10000; i++)
    {
        fn= fn+(1/(i*i*i*i));
    }
    printf("\n fn crescente= %f", fn);
    et = ((vr - fn)/vr)*100;
    printf("\n fn crescente et = %f %%", et);

    fn=0;

    for(i=10000; i>=1; i--)
    {
        fn= fn+(1/(i*i*i*i));
    }
    printf("\n fn decrescente= %f", fn);
    et = ((vr - fn)/vr)*100;
    printf("\n fn decrescente et = %f %%", et);

    return 0;
}
