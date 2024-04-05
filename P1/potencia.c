// Função recursiva que calcula uma base elevado a um expoente recursivamente

int potencia(int base, int expoente){
int resultado;
if(expoente == 0) return 1;
else if (expoente == 1) return base;
else {
    resultado = base * potencia(base, expoente - 1);
}
return resultado;
}

int main(){

    int base = 2, expoente = 1, resultado;

    resultado = potencia(base, expoente);

    printf("O fatorial eh %d", resultado);
    
    return 0;
}