// Aqui o código é igual, a unica difrenca é a linha comentada a baixo.

//O gettid pega o ID definido pelo kernel, esse ID é proximo do ID do processo, o mesmo ID que pode ser visto usando htop no linux
//Ja o thrd_current cria um ID unico para a thread, porem, esse ID pode ser re-utilizado quando a thread é terminada.

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void *imprime(void *i){
    printf("Eu sou a thread %ld e meu ID é %lu.\n",++i,thrd_current());
    printf("Usando getid, a thread %ld terá o ID %lu.\n",i,gettid()); // Uso do gettid
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