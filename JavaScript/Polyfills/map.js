let cb = function (item, index) {
  return item * 2;
};
Array.prototype.myMap = function (cb) {
  let arr = this;
  let result = [];
  for (let i = 0; i < arr.length; i++) {
    result.push(cb(arr[i], i));
  }
  return result;
};

console.log(
  [1, 2, 3, 5, 6].map((item) => item * 2),
  [1, 2, 3, 5, 6].myMap(cb)
);
