// Soma dos num int de um vetor de forma recursiva

#include <stdio.h>

int soma(int v[], int tam){

    if(tam <= 0) return 0;
    if(v[tam - 1] > 0) return v[tam - 1] + soma(v, tam - 1);
    else return soma(v, tam - 1);
}

int main(){

    int v[5] = {1, 2, 3, 4, 5};
    int tam = 5;
    int X = 3;

    int resposta = soma(v,tam);

    printf("%d", resposta);
}