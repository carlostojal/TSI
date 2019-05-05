#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main()
{
    int random,corda;
    float x;
    time_t t;

    srand((unsigned) time(&t));

    while(1)
    {
        random=rand()%20;
        if (random==0)
        {
            continue;
        }
        else if(random%10==0)
        {
            corda=random;
            break;
        }
        else if(random%12==0)
        {
            corda=random;
            break;
        }
        else if(random%15==0)
        {
            corda=random;
            break;
        }
    }

    x=sqrt(pow(corda,2)-pow(6,2));

    printf("Com um cabo de %dm, teria de a fixar a %.2fm da parede.\n",corda,x);
}
