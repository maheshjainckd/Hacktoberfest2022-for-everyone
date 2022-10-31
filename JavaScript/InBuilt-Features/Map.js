// The map() method is used for creating a new array from an existing one, applying a function to each one of the elements of the first array.

// Syntex
var new_array = arr.map(function callback(element, index, array) {
    // Return value for new_array
}[, thisArg])



// In the following example, each number in an array is doubled.

const numbers = [1, 2, 3, 4];
const doubled = numbers.map(item => item * 2);
console.log(doubled); // [2, 4, 6, 8]




// In the following example, each number in an array is squered.

const numbers = [1, 2, 3, 4];
const squered = numbers.map(item => item * item);
console.log(squered); // [1, 4, 9, 16]
