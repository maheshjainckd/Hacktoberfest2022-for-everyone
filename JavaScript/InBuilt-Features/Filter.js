// The filter() method takes each element in an array and it applies a conditional statement against it.
// If this conditional returns true, the element gets pushed to the output array. If the condition returns false, 
// the element does not get pushed to the output array.

// Syntex
var new_array = arr.filter(function callback(element, index, array) {
    // Return true or false
}[, thisArg])

// The syntax for filter is similar to map, except the callback function should return true to keep the element,
// or false otherwise. In the callback, only the element is required.

// Example
const numbers = [1, 2, 3, 4];
const evens = numbers.filter(item => item % 2 === 0);
console.log(evens); // [2, 4]

// In the next example, filter() is used to get all the students whose grades are greater than or equal to 90.

const students = [
  { name: 'Quincy', grade: 96 },
  { name: 'Jason', grade: 84 },
  { name: 'Alexis', grade: 100 },
  { name: 'Sam', grade: 65 },
  { name: 'Katie', grade: 90 }
];

const studentGrades = students.filter(student => student.grade >= 90);
return studentGrades; // [ { name: 'Quincy', grade: 96 }, { name: 'Alexis', grade: 100 }, { name: 'Katie', grade: 90 } ]
