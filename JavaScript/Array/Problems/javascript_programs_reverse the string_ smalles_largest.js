// reverse a string___________________

function reverse(str) {
  var newstr = '';
  for (var i = str.length - 1; i >= 0; i--) {
    newstr += str[i];
  }
  return newstr;
}
console.log(reverse([1, 3, 4]));

// find largest smallest ___________________

var arr = [3, 6, 2, 56, 32, 5, 89, 32];
var largest = arr[0];

for (var i = 0; i < arr.length - 1; i++) {
  if (largest > arr[i]) {
    largest = arr[i];
  }
}
console.log(largest);

// second largest number____________________________
const output = [3, 6, 2, 56, 32, 5, 89, 32].sort((a, b) => b - a)[1];

console.log(arr);
