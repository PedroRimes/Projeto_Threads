#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void *imprime(void *i){
    printf("Eu sou a thread %ld e meu ID é %lu.\n",++i,thrd_current());
    printf("Usando getid, a thread %ld terá o ID %lu.\n",i,gettid());
}


int main (void)
{
    int n = 0, i;
    printf("Digite a quantidade desejada de threads = ");
    scanf("%d", &n);
    thrd_t threads[n];


    for(i = 0; i < n; i++)
    {
        thrd_create(&threads[i], imprime,(void *)i);
    }

    thrd_exit(0);

}