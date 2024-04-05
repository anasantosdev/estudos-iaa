// Função recursiva que calcula a soma dos dígitos de um int positivo n. 

#include <stdio.h>

int soma(int a){
    if(a < 10) {
        return a;
    } else {
        return (a % 10 ) + soma (a / 10);
    }
}

int main(){

    int a = 12;

    int resultado = soma(a);

    printf("%d", resultado);

    return 0;
}