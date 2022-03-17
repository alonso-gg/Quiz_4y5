#include "main.h"
#define MIN(a,b) ((a) < (b) ? (a) : (b)) //suma 1 comparación donde aparece
#define MAX(a,b) ((a) > (b) ? (a) : (b)) //suma 1 comparación donde aparece
#define ACCESIBLE(var, i, n) ((i) < (n) ? (var) : (0)) //suma 1 comparación donde aparece

/*ITCR Campus Central Cartago
Análisis de Algoritmos - Quices 4 y 5
I Semestre 2022
Estudiante: Alonso Garita Granados
*/

/*Chocolate NxM :Este algoritmo necesita que los arreglos 'x' y 'y' estén en orden descendente
M = tamaño de x+1  |  N = tamaño de y+1  |  k = M o N, el que sea mayor

Función f:
f(k, M, N) = (17) + (2 + 6M + 6N + 6) + (32k) + 4
f(k, M, N) = 32k + 6M + 6N + 29
-Dado que k siempre es igual a M o N, podemos dar f en términos de M y N tal que:
    f(M, N) = 38M + 6N + 29 ; cuando k = M
    f(M, N) = 6M + 38N + 29 ; cuando k = N
-Por lo tanto, la tasa de crecimiento depende tanto de M como de N, así que el peso de ambos se refleja en
la tasa de crecimiento.

Notación: O(M+N)

Loop invariant:
    Cualquier costo candidato es menor que C = (sum(x[i])*N + sum(y[i])*M)
    -Esto porque C sería el costo de hacer cortes de 1x1 en todo el chocolate, es decir, el mayor costo
    posible y determina una cota superior para todos los costos posibles. C se calcula con el M y N de
    input, antes de decrementarlos.
*/

int costo(int M, int N, int x[], int y[]){
    //Asignaciones iniciales (17 tiempos)
    int sumX = 0, sumY = 0; //2 asignaciones
    int sumAltX, sumAltY;
    int vertical, horizontal;
    int iX = 0, iY = 0; //2 tiempos
    int maxLength = MAX(M, N); //1 asignación, 1 comparación = 2 tiempos
    int minLength = MIN(M, N); //1 asignación, 1 comparación = 2 tiempos
    M--; //2 tiempos
    N--;//2 tiempos

    sumAltX = x[iX]; //2 tiempos
    sumAltY = y[iY]; //2 tiempos

    int i=2; //1 asignación

    //Cortes intercalados (32k tiempos)
    do{ //dowhile máximo: maxLength (k)
        iX++; iY++; //4 tiempos
        sumAltX += i*(ACCESIBLE(y[iY-1], iY-1, N) + ACCESIBLE(x[iX], iX, M)); //12 tiempos 
        sumAltY += i*(ACCESIBLE(x[iX-1], iX-1, M) + ACCESIBLE(y[iY], iY, N)); //12 tiempos 

        if(i<minLength) //1 comparación
            i++; //2 tiempos
    }while(iX < maxLength); //1 comparación

    //Cortes paralelos (2 + 6M + 6N + 6 tiempos)
    //1 asignación
    for(i=0; i<M; i++){ //3 tiempos
        sumX += x[i]; //3 tiempos
    } //forsize: M

    //1 asignación
    for(i=0; i<N; i++){ //3 tiempos
        sumY += y[i]; //3 tiempos
    } //forsize: N
    
    vertical = sumX + ((M+1) * sumY); // 3 tiempos
    horizontal = sumY + ((N+1) * sumX); // 3 tiempos

    //Impresiones de todos los costos candidatos, no se suman al conteo para f porque son para revisar
    //todos los valores obtenidos.
    cout << "Verticales: " << vertical << endl;
    cout << "Horizontales: " << horizontal << endl;
    cout << "Vertical intercalado: " << sumAltX << endl;
    cout << "Horizontal intercalado: " << sumAltY << endl;

    //3 comparaciones
    return MIN(MIN(horizontal, vertical), MIN(sumAltX, sumAltY)); //1 retorno
}