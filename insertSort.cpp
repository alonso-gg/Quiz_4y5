#include "main.h"

/*ITCR Campus Central Cartago
Análisis de Algoritmos - Quices 4 y 5
I Semestre 2022
Estudiante: Alonso Garita Granados

**Este algoritmo no es objeto de evaluación**
*/

void insertionSort(int arr[], int n){
   int aux, j;

   for(int i = 1; i<n; i++){
      aux = arr[i];
      j = i;

      while(j > 0 && arr[j-1]<aux) {
         arr[j] = arr[j-1];
         j--;
      }

      arr[j] = aux;
   }
}