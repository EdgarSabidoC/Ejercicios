#include <stdio.h>

/**
 * Por: Edgar Sabido Cortés. 
 */


/** 
 * La función modifica el arreglo original que es donde
 * se cambian las posiciones (simulando el merge), ya que
 * el arreglo se pasa por referencia (se pasa la dirección
 * del arreglo).
 * 
 * PARÁMETROS:
 * 
 * A[] = Arreglo de enteros.
 * l = Índice que apunta al inicio del arreglo (left).
 * m = Índice que apunta a la mitad del arreglo (middle).
 * r = Índice que apunta al final del arreglo (right).
 * 
 */
void merge(int A[], unsigned int l, unsigned int m, unsigned int r) {
    
    unsigned int i, j, k;
    
    // Tamaño de los arreglos temporales:
    unsigned int L_size = m - l + 1;
    unsigned int R_size = r - m;
    
    // Arreglos temporales:
    int L[L_size], R[R_size];
    
    // Se copian los elementos del arreglo original a los arreglos temporales:
    
    // Arreglo temporal izquierdo:
    for(i = 0; i < L_size; ++i)
        L[i] = A[l+i];
    // Arreglo temporal derecho:
    for(i = 0; i < R_size; ++i)
        R[i] = A[m + 1 + i];
    
    // índice que indica el principio del subarreglo izquierdo:
    i = 0;
    // índice que inda el principio del subarreglo derecho:
    j = 0;
    // índice que indica la posición actual dentro del arreglo original:
    k = l;
    
    while(i < L_size && j < R_size) {
        // Si el elemento del arreglo izquierdo es menor o igual
        // al del arreglo derecho, entonces el elemento
        // del arreglo izquierdo se guarda en la posición actual
        // del arreglo original:
        if(L[i] <= R[j]){
            A[k] = L[i];
            i++;
        }
        // Si no, el elemento del arreglo derecho se guarda en la 
        // posición actual del arreglo original:
        else {
            A[k] = R[j];
            j++;
        }
        // Se aumenta el índice de arreglo original
        k++;
    }
    
    // Se verifica que no quede ningún elemento
    // en los arreglos temporales:
    
    // Arreglo temporal izquierdo:
    while(i < L_size) {
        A[k] = L[i];
        i++;
        k++;
    }
    
    // Arreglo temporal derecho:
    while(j < R_size) {
        A[k] = R[j];
        j++;
        k++;
    }
}

/**
 * La función ordena un arreglo de enteros en orden ascendente.
 * La función modifica el arreglo original, ya que se pasa
 * por referencia (dirección del arreglo). Cuando se realizan
 * los llamados recursivos sólo pasa los índices para
 * hacer la partición (se simula), de esa manera no se hace un gasto
 * extra en la memoria teniendo que crear otros subarreglos.
 * 
 * PARÁMETROS:
 * 
 * A[] = Arreglo de enteros.
 * l = Índice que apunta al inicio del arreglo (left).
 * r = Índice que apunta al final del arreglo (right).
 * 
 */
void* mergesort(int A[], unsigned int l, unsigned int r) {
    
    // Si el índice izquierdo es menor al índice derecho:
    if(l < r) 
    {    
        // Se calcula la mitad del arreglo, m es el
        // índice que apunta a la mitad del arreglo:
        //unsigned int m = (r+l)/2; 
        unsigned int m = l + ((r - l)/2); // Para números de l y r muy grandes.
        
        // Se llama recursivamente al mergesort
        // simulando la partición al indicar los índices,
        // evitando así el crear copias o hacer uso de 
        // arreglos temporales:

        // Se la pasan los índices de l a la mitad del arreglo:
        mergesort(A, l, m);
        // Se le pasan los índices desde la mitad del arreglo+1 hasta el final del arreglo:
        mergesort(A, m+1, r); 
        
        // Se llama a la función merge para unir
        // las dos partes del arreglo:
        merge(A, l, m, r);
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
void printArray(int A[], int array_size) {
  unsigned int i;
  printf("[");
  for(i = 0; i < array_size-1; ++i) {
    printf("%d, ", A[i]);
  }
  printf("%d]\n", A[i]);
}


int main() {
    
    int A[] = {3, 1, 4, 2};
    size_t array_size = sizeof(A)/sizeof(A[0]);
  
    mergesort(A, 0, array_size-1);
    printArray(A, array_size);

    // ------------------------------------------------------------------------------

    int B[] = {-1};
    array_size = sizeof(B)/sizeof(B[0]);
    
    mergesort(B, 0, array_size-1);
    printArray(B, array_size);

    // ------------------------------------------------------------------------------

    int C[] = {-1, 500, 1024, 256, 128, 64, 0, 32, 16, 4, 8, 2, 512, -7, -4};
    array_size = sizeof(C)/sizeof(C[0]);
  
    mergesort(C, 0, array_size-1);
    printArray(C, array_size);

    return 0;
}