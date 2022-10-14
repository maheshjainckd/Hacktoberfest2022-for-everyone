let arr = [4, 7, 8, 1, 6, 3];
arr.sort((a, b) => b - a); //inc ---> neg  , desc ---> pos
console.log(arr);

Array.prototype.mySort = function (cb = (a, b) => a - b) {
  let arr = this;
  for (let i = 0; i < arr.length; i++) {
    for (let j = i + 1; j < arr.length; j++) {
      //increasing order
      if (cb(arr[i], arr[j]) > 0) {
        // 4- 7 = -3 --> don't swap , //7-4=3 --> swap
        swap(i, j);
      }
    }
  }

  function swap(num1, num2) {
    let temp;
    temp = arr[num1];
    arr[num1] = arr[num2];
    arr[num2] = temp;
  }

  return this;
};
let arr2 = arr.mySort();
console.log("inc", arr2);
let arr3 = arr.mySort((a, b) => b - a);
console.log("decs", arr3);
