#include <stdio.h>
#include <string.h>
#include <threads.h>


int main (void)
{
    int n = 0, i;
    printf("Digite a quantidade desejada de threads = ");
    scanf("%d", &n);
    thrd_t threads[n];


    for(i = 0; i < n; i++)
    {
        thrd_create(&threads[i], imprime,(void *));
    }

}