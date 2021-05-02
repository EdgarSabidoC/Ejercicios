#include <stdio.h>

/**
 * Por: Edgar Sabido Cortés 
 */

/**
 *   
 * La función recibe la dirección de dos
 * números enteros y los intercambia.
 * 
 */
void swap(int *num1, int *num2){

  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

/**
 * 
 * La función toma el primer elemento del arreglo
 * como pivote y lo coloca en su posición ordenada
 * en el arreglo. Coloca los elementos menores al
 * pivote en el lado izquierdo y a los mayores en
 * el lado derecho del pivote.
 * 
 * A[] = Arreglo de enteros.
 * l = Inicio del arreglo/subarreglo (low).
 * h = Fin del arreglo/subarreglo (high).
 * 
 */
unsigned int partition(int A[], unsigned int l, unsigned int h) {

  // El pivote se toma del inicio del arreglo y subarreglos (primer elemento):
  int pivot = A[l];

  unsigned int i = l; // índice que apunta al principio del arreglo.
  unsigned int j = h; // índice que apunta al final del arreglo.

  // Se repite hasta que el índice i sea menor al j:
  while(i < j) {

    // Se aumenta el índice i hasta que se encuentre un
    // elemento mayor al pivote:
    do{
      ++i;
    } while(A[i] <= pivot);

    // Se decrementa el índice j hasta que se encuentre un
    // elemento menor o igual al pivote:
    do{
      --j;
    } while(A[j] > pivot);

    // Si el índice i apunta a un elemento mayor al
    // elemento que apunta el índice j, entonces
    // se intercambian:
    if(i < j){
      swap(&A[i], &A[j]);
    }
  }

  // El pivote se coloca en su posición ordenada:
  swap(&A[l], &A[j]);
  
  // Se retorna la posición ordenada del pivote:
  return j;
}

/**
 * 
 * Función que implementa el quicksort
 * a través del paradigma divide y conquistarás
 * (Divide and Conquer). Es recursiva.
 * 
 * A[] = Arreglo de enteros.
 * low = Índice al inicio del arreglo.
 * high = Índice al final del arreglo.
 * 
 */
void quicksort(int A[], unsigned int low, unsigned int high) {
  if(low < high) {

    // Se crea la partición y se obtiene la 
    // posición del pivote:
    int p = partition(A, low, high);
    
    // Se realiza el llamada para ambas partes:
    quicksort(A, low, p); // Elementos menores o iguales al pivote.
    quicksort(A, p+1, high); // Elementos mayores al pivote.
  }
}

/**
 * 
 * Función que imprime un arreglo de enteros.
 * 
 * A[] = Arreglo de enteros.
 * array_size = Cantidad de elementos del arreglo.
 * 
 */
void printArray(int A[], size_t array_size) {
  int i;
  printf("[");
  for(i = 0; i < array_size-1; ++i) {
    printf("%d, ", A[i]);
  }
  printf("%d]\n", A[i]);
}

int main () {

  int A[] = {3, 1, 4, 2};
  size_t array_size = sizeof(A)/sizeof(A[0]);
  
  quicksort(A, 0, array_size);
  printArray(A, array_size);

  // ------------------------------------------------------------------------------

  int B[] = {-1};
  array_size = sizeof(B)/sizeof(B[0]);
  
  quicksort(B, 0, array_size);
  printArray(B, array_size);

  // ------------------------------------------------------------------------------

  int C[] = {-1, 500, 1024, 256, 128, 64, 0, 32, 16, 4, 8, 2, 512, -7, -4};
  array_size = sizeof(C)/sizeof(C[0]);
  
  quicksort(C, 0, array_size);
  printArray(C, array_size);

  return 0;
}