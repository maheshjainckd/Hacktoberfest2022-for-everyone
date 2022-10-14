//QUICK SORT
function swap(arr, num1, num2) {
  let temp = arr[num1];
  arr[num1] = arr[num2];
  arr[num2] = temp;
}

function sortOneElement(arr, start, end) {
  let pivot = arr[end];
  let currPivotCorrectIndex = start - 1;
  for (let i = start; i < end; i++) {
    if (arr[i] < pivot) {
      currPivotCorrectIndex++;
      swap(arr, i, currPivotCorrectIndex);
    }
  }
  swap(arr, currPivotCorrectIndex + 1, end);
  return currPivotCorrectIndex + 1;
}

function quickSort(arr, start, end) {
  if (start < end) {
    let partition = sortOneElement(arr, start, end);
    quickSort(arr, start, partition - 1);
    quickSort(arr, partition + 1, end);
  }
  return arr;
}

console.log(quickSort([20, 40, 10, 60, 5, 70], 0, 5));
