#include <stdio.h>

/* Rearranja o vetor v[0..n-1] em ordem crescente. */
void Seleção (int n, int v[]) {
int i, j, min, x;
for (i = 0; /*A*/ i < n-1; i++) {
min = i;
for (j = i+1; j < n; j++)
if (v[j] < v[min]) min = j;
x = v[i]; v[i] = v[min]; v[min] = x;
}
}

int main(){
    int n = 10;
    int v[n];
}