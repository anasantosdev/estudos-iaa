
#include <stdio.h>

/* A função recebe vetores crescentes v[p..q-1] e v[q..r-1]
* e rearranja v[p..r-1] em ordem crescente. */
void Intercala (int p, int q, int r, int v[]) {
int i, j, k, *w;
w = malloc ((r-p) * sizeof (int));
i = p; j = q; k = 0;
while (i < q && j < r) {
if (v[i] <= v[j]) w[k++] = v[i++];
else w[k++] = v[j++];
}
while (i < q) w[k++] = v[i++];
while (j < r) w[k++] = v[j++];
for (i = p; i < r; i++) v[i] = w[i-p];
free (w); 
}

int main(){
    int n = 10;
    int v[n];
}
