#include <stdio.h>

/* Esta função recebe um max-heap v[1..m] e transforma
* v[1..m+1] em max-heap. */
void InsereEmHeap (int m, int v[]) {
int f = m+1;
while /*X*/ (f > 1 && v[f/2] < v[f]) {
int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
f = f/2;
}
}

void SacodeHeap (int m, int v[]) {
int t, f = 2;
while /*X*/ (f <= m) {
if (f < m && v[f] < v[f+1]) ++f;
if (v[f/2] >= v[f]) break;
t = v[f/2]; v[f/2] = v[f]; v[f] = t;
f *= 2;
}
}

/* Rearranja o vetor v[1..n] de modo que ele fique
* crescente. */
void Heapsort (int n, int v[]) {
int m;
for (m = 1; m < n; m++)
InsereEmHeap (m, v);
for (m = n; /*X*/ m > 1; m--) {
int t = v[1]; v[1] = v[m]; v[m] = t;
SacodeHeap (m-1, v);
}
}


int main(){
    int n = 10;
    int v[n];
}