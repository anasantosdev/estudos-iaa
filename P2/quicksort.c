#include <stdio.h>

/* Recebe um vetor v[p..r] com p <= r. Rearranja os
* elementos do vetor e devolve j em p..r tal que
* v[p..j-1] <= v[j] < v[j+1..r]. */
int Separa (int p, int r, int v[]) {
int c, j, k, t;
c = v[r]; j = p;
for (k = p; /*A*/ k < r; k++)
if (v[k] <= c) {
t = v[j], v[j] = v[k], v[k] = t;
j++;
}
v[r] = v[j], v[j] = c;
return j;
}

/* Esta função rearranja o vetor v[p..r], com p <= r+1,
* de modo que ele fique em ordem crescente. */
void Quicksort (int p, int r, int v[]) {
int j;
if (p < r) {
j = Separa (p, r, v);
Quicksort (p, j - 1, v);
Quicksort (j + 1, r, v);
}
}

/* Esta função rearranja o vetor v[p..r], com p <= r+1,
* de modo que ele fique em ordem crescente. */
void QuickSort (int p, int r, int v[]) {
int j;
while (p < r) {
j = Separa (p, r, v);
if (j - p < r - j) {
QuickSort (p, j - 1, v);
p = j + 1;
} else {
QuickSort (j + 1, r, v);
r = j - 1;
}
}
}



int main(){

}