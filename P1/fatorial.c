#include <stdio.h>

int fatorial(int x){
int resultado;
if(x < 2){
    resultado = 1;
}else{
    resultado = x * fatorial(x-1);
}
return resultado;
}

int main(void){

    int num, resultado;

    printf("Digite um num int");
    scanf("%i", &num);

    resultado = fatorial(num);

    printf("O fatorial eh %d", resultado);

    int fatorial(int x);
    
    system("pause");
    return 0;
}