#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <threads.h> //biblioteca requisitada


void imprime(void *name)//função para imprimir as threads e o seu ID usando thrd_current como requisitado
{
    printf("Eu sou a %s e meu ID é %lu.\n",name,thrd_current());//thrd_current é usado para pegar o ID que o sistema operacional da para a thread
}


int main (void)//main é criada
{
    int n = 0, i;// criado a variavel que vai receber os nomes e agir como contador
    char name[10];
    printf("Digite a quantidade desejada de threads = ");
    scanf("%d", &n);
    thrd_t threads[n];// é definido as threads
    for(i = 0; i < n; i++)
    {
        sprintf(name, "thread_%d", i);
        thrd_create(&threads[i], imprime,(void *)name);//é feito a criação das threads juntamente da chamada da função com o print para o usuario
    }
    thrd_exit(0); //codigo criado para fechar a thread
    // poderia usar join, mas acredito estar errado, join apenas bloqueia, exit termina.
}

// Um ponto interessante em relação ao código, é que as threads se sobrepoem durante o print.

//https://en.cppreference.com/w/c/thread