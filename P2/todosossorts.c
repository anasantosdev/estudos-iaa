#include <stdio.h>
#include <stdlib.h>

// --- Algoritmos Elementares --- //

int BubbleSort(int array[], n)
{
for (int i = 0 ; i < n - 1; i++)
  {
    for (int j = 0 ; j < n - i - 1; j++)     //n é o tamanho do array
    {
      if (array[j] > array[j+1])      // Para o uso com ordem decrescente 
      {
        int swap   = array[j];
        array[j]   = array[j+1];
        array[j+1] = swap;
      }
    }
  }
}

void insertionSort(int arr[], int n) 
{ 
   int i, key, j; 
   for (i = 1; i < n; i++) 
   { 
       key = arr[i]; 
       j = i-1;
       while (j >= 0 && arr[j] > key) 
       { 
           arr[j+1] = arr[j]; 
           j = j-1; 
       } 
       arr[j+1] = key; 
   } 
} 

void SelectionSort(int v[], int N){
    int i, j, min, aux;

/*Seleciona o menor elemento e o elemento atual a cada iteração, 
comparando qual é maior e ordenando o vetor*/  

    for(i=0; i<(N-1); i++){
        v[i] = min;
        for(j=1; j<N; j++){
            if(v[min] > v[j]){
                min = j;
            }
            if(min != i){
                aux = v[i];
                v[i] = v[min];
                v[min] = aux; 
            }
        }
    }
    
}

// --- Algoritmos Eficientes --- //

void MergeSort(int v[], int N){

}

void HeapSort(int v[], int N){

}

void CountingSort(int v[], int N){

}






int main(){
    int N = 5;

    int v[5]= {0, 1, 2, 1, 4};

    return 0;
}