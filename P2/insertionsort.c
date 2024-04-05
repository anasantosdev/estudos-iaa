#include <stdio.h>

void Inserção (int n, int v[]) {
int i, j, x;
for (j = 1; /*A*/ j < n; j++) {
x = v[j];
for (i = j-1; i >= 0 && v[i] > x; i--)
v[i+1] = v[i];
v[i+1] = x;
}
}

int main(){
    int n = 10;
    int v[n];
}