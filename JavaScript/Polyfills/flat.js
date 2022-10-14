Array.prototype.myFlat = function (depth = 1) {
  let result = [];
  let arr = this;
  function inner() {
    for (let i = 0; i < arr.length; i++) {
      if (Array.isArray(arr[i]) && depth > 0) {
        result = result.concat(arr[i].myFlat(depth - 1));
      } else {
        result.push(arr[i]);
      }
    }
    return result;
  }
  inner();
  return result;
};

console.log([1, 2, [3, [5, [6]]]].flat(2), [1, 2, [3, [5, [6]]]].myFlat(3));
