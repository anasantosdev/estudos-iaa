// Busca Binária recursiva

#include <stdio.h>

int busca_Binaria(int v[], int X, int tam){
    int meio = tam / 2;

    if(v[meio] == X){
        return meio;
    } else {
        int tam2 = meio / 2;

        busca_Binaria(v, X, tam2);
        busca_Binaria(v, X, tam2);
    }
}

int main(){

    int v[5] = {1, 2, 3, 4, 5};
    int tam = 5;
    int X = 3;

    int resposta = busca_Binaria(v, X, tam);

    printf("%d", resposta);
}