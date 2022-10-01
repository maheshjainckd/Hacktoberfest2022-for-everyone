// Bubble Sort algorithm implementation in JavaScript

let array = [234, 43, 55, 63, 23, 5, 6, 235, 547, 1];
console.log('Before Sorting: ' + array)
bubbleSort(array);
console.log('After Sorting: ' + array)

// Time: Best Case- O(1),   Worst Case- O(N ^ 2)
function bubbleSort(array) {
    for (let i = 0; i < array.length; i++) {
        let isSwapped = false;
        for (let j = 0; j < array.length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                // Swap
                var temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
                isSwapped = true;
            }
        }
        count++;
        if (!isSwapped) break; // Check to avoid unnecessary iteration
    }
}

