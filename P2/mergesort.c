#include <stdio.h>

/* Rearranja o vetor v[0..n-1] em ordem crescente. */
void MergesortI (int n, int v[]) {
int p, r;
int b = 1;
while (b < n) {
p = 0;
while (p + b < n) {
r = p + 2*b;
if (r > n) r = n;
Intercala (p, p + b, r, v);
p = p + 2*b;
}
b = 2*b;
}
}

// -- Versão Recursiva 
void Mergesort (int p, int r, int v[]) {
if (p < r - 1) {
int q = (p + r)/2;
Mergesort (p, q, v);
Mergesort (q, r, v);
Intercala (p, q, r, v);
}
}

int main(){
    int n = 10;
    int v[n];
}