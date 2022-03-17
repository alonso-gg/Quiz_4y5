#include "main.h"

/*ITCR Campus Central Cartago
Análisis de Algoritmos - Quices 4 y 5
I Semestre 2022
Estudiante: Alonso Garita Granados
*/

/*Radix sort
n = Tamaño del arreglo (arr)  |  max = m = mayor cant. de dígitos

Función f:
f(n, m) = 3 + ( 11 + 11n + 2 + (3 + 14n)*10) * m
f(n, m) = 3 + ( 13 + 11n + 30 + 140n ) * m
f(n, m) = 3 + ( 43 + 151n ) * m
f(n, m) = 3 + 43m +151nm
-En la función el término de mayor dominancia es nm, así que de eso depende la tasa de crecimiento.

Notación: O(n*m)

Loop invariant:
    El arreglo está ordenado según el (i+1)-ésimo dígito.
    Cuando no ha entrado al ciclo estaría ordenado por el 0-ésimo dígito, es decir, en desorden.*/

void radixSort(int* arr, int n, int max){
    int i, j, m, p = 1, index, temp, count = 0;  //2 asignaciones
    list<int> pocket[10];

    //1 asignación
    for(i = 0; i<max; i++){  //3 tiempos
        m = pow(10, i+1);  //4 tiempos
        p = pow(10, i);  //3 tiempos

        //1 asignación
        for(j = 0; j<n; j++){  //3 tiempos
            temp = arr[j]%m;  //3 tiempos
            index = temp/p;  //2 tiempos
            pocket[index].push_back(arr[j]);  //3 tiempos
        } //forsize: n

        count = 0;  //1 asignación

        //1 asignación
        for(j = 0; j<10; j++){  //3 tiempos
            while(!pocket[j].empty()){  //4 tiempos
                arr[count] = *(pocket[j].begin());  //4 tiempos
                pocket[j].erase(pocket[j].begin());  //4 tiempos
                count++;  //2 tiempos
            } //while maximo: n | 14n
        } //for size: 10 | 10*14n
    } //for size: max (m)    
}