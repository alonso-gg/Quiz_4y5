#include "main.h"

/*ITCR Campus Central Cartago
Análisis de Algoritmos - Quices 4 y 5
I Semestre 2022
Estudiante: Alonso Garita Granados

Incluye:
    -main.cpp: este archivo.
    -chocolate.cpp: resolución del primer punto del quiz.
    -radixSort.cpp: resolción del segundo punto del quiz.
    -insertSort.cpp: se usa para ordenar los arreglos de entrada para el primer punto, no es para evaluar.
    -main.h: includes generales y encabezados de todos los algoritmos.
*/

int main(){
    int x_1[] = {9, 7, 8};
    int y_1[] = {3, 2, 4, 5, 1, 6};
    insertionSort(x_1, 3);
    insertionSort(y_1, 6);
    int costo1 = costo(4, 7, x_1, y_1);

    cout  << "Costo 1: " << costo1 << endl << endl;

    int x_2[] = {2, 3, 5, 11};
    int y_2[] = {8, 9};
    insertionSort(x_2, 4);
    insertionSort(y_2, 2);
    int costo2 = costo(5, 3, x_2, y_2); //Los arreglos 'x' y 'y' deben ir en orden descendente

    cout  << "Costo 2: " << costo2 << endl;

    return 0;
}