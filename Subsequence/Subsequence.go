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

package main

import "fmt"

func main() {
	var (
		arreglo   = []int{5, 1, 22, 25, 6, -1, 8, 10}
		secuencia = []int{1, 6, -1, 10}

		// arreglo = []int{1, 2, 3, 4}
		// secuencia = []int{1, 3, 4}

		// arreglo = []int{1}
		// secuencia = []int{1}
	)

	fmt.Printf("%t", esSubSecuencia(arreglo, secuencia))
}

func esSubSecuencia(arreglo []int, secuencia []int) bool {
	var (
		elemArr int = 0
		elemSec int = 0
	)

	for elemArr = 0; elemArr < len(arreglo) && elemSec < len(secuencia); elemArr++ {
		if secuencia[elemSec] == arreglo[elemArr] {
			elemSec++
		}
	}

	if elemSec == len(secuencia) {
		return true
	}

	return false
}
