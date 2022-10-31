package main

import "fmt"

func main() {
	numbers := []int{6, 4, 17, 3, 2, 9, 13}
	insertionSort(numbers)
	fmt.Println(numbers)
}

func insertionSort(numbers []int) {
	for i := 0; i < len(numbers); i++ {
		currentNumber := numbers[i]
		currentIndex := i

		for currentIndex > 0 && numbers[currentIndex-1] > currentNumber {
			numbers[currentIndex] = numbers[currentIndex-1]
			currentIndex--
		}

		numbers[currentIndex] = currentNumber
	}
}
