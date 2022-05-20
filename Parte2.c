#include<stdio.h>


int main ()
{
    int m = 10, n = 10, i, j, matriz1[10][10], matriz2[10][10], matrizsom[10][10];
    
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            matriz1[i][j] = 1;
            matriz2[i][j] = 1;
        }
    }
    
    for(i = 0; i<10; i++){
        for(j = 0; j < 10; j++){
            matrizsom[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}
