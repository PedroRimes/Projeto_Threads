// Aqui o código é igual, a unica difrenca é a linha comentada a baixo.

//O gettid pega o ID definido pelo kernel, esse ID é proximo do ID do processo, o mesmo ID que pode ser visto usando htop no linux
//Ja o thrd_current cria um ID unico para a thread, porem, esse ID pode ser re-utilizado quando a thread é terminada.
#include <sys/syscall.h>
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void imprime(void *name){
    printf("Eu sou a %s e meu ID é %lu.\n",name,thrd_current());
    printf("Usando getid, a %s terá o ID %lu.\n",name,gettid()); // Uso do gettid
}


int main (void)
{
    int n = 0, i;
    char name[10];
    printf("Digite a quantidade desejada de threads = ");
    scanf("%d", &n);
    thrd_t threads[n];


    for(i = 0; i < n; i++)
    {
        sprintf(name, "thread_%d", i);
        thrd_create(&threads[i], imprime,(void *)name);
    }

    thrd_exit(0);

}