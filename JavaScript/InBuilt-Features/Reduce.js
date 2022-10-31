// The reduce() method reduces an array of values down to just one value. To get the output value, 
//   it runs a reducer function on each element of the array.

// Syntax
arr.reduce(callback[, initialValue])

// The callback argument is a function that will be called once for every item in the array. 
// This function takes four arguments, but often only the first two are used.

// ⚫ accumulator - the returned value of the previous iteration
// ⚫ currentValue - the current item in the array
// ⚫ index - the index of the current item
// ⚫ array - the original array on which reduce was called
// ⚫ The initialValue argument is optional. If provided, it will be used as the initial accumulator value in the first call to the callback function.

// Example
// The following example adds every number together in an array of numbers.

const numbers = [1, 2, 3, 4];
const sum = numbers.reduce(function (result, item) {
  return result + item;
}, 0);
console.log(sum); // 10


// Counting Frequency
var pets = ['dog', 'chicken', 'cat', 'dog', 'chicken', 'chicken', 'rabbit'];

var petCounts = pets.reduce(function(obj, pet){
    if (!obj[pet]) {
        obj[pet] = 1;
    } else {
        obj[pet]++;
    }
    return obj;
}, {});

console.log(petCounts); 

/*
Output:
 { 
    dog: 2, 
    chicken: 3, 
    cat: 1, 
    rabbit: 1 
 }
