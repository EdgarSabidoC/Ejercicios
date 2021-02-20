/**
 * Subsequence:
 * 
 * Given two non-empty arrays of integers, write a function that determines 
 * whether the second array is a subsequence of the first one.
 * A subsequence of an array is a set of numbers that aren't necessarily adjacent 
 * in the array but that are in the same order as they appear in the array. 
 * For instance, the numbers [1, 3, 4] form a subsequence of the array,
 * [1, 2, 3, 4], and so do the numbers [2, 4].
 * 
 * Note: that a single number in an array and the array itself are both valid subsequences of the array.
 * 
 * Example:
 * array= [5, 1, 22, 25, 6, -1, 8, 10]
 * sequence = [1, 6, -1, 10]
 */

#include <stdio.h>

int esSubSecuencia(int *arreglo, int *secuencia, unsigned int tam_arr, unsigned int tam_sec);

int main(void) 
{

  // int arreglo[] = {1, 2, 3, 4}; 
  // int secuencia[] = {1, 2, 4};
 
  int arreglo[] = {5, 1, 22, 25, 6, -1, 8, 10};
  int secuencia[] = {1, 6, -1, 10};

  // int arreglo[] = {1};
  // int secuencia[] = {1}; 
  
  unsigned int tam_arr = sizeof(arreglo)/sizeof(arreglo[0]);
  unsigned int tam_sec = sizeof(secuencia)/sizeof(secuencia[0]);

  esSubSecuencia(arreglo, secuencia, tam_arr, tam_sec);
  
  return 0;
}

// Retorna 1 si es verdad, 0 si es falso.
int esSubSecuencia(int *arreglo, int *secuencia, unsigned int tam_arr, unsigned int tam_sec)
{
  unsigned int elem_arr = 0;
  unsigned int elem_sec = 0;

  for (elem_arr = 0; (elem_arr < tam_arr && elem_sec < tam_sec); ++elem_arr)
    if (secuencia[elem_sec] == arreglo[elem_arr])
      ++elem_sec;

  if (elem_sec == tam_sec) 
  {
    printf("true\n");
    return 1;
  }

  printf("false\n");
  return 0;
}
