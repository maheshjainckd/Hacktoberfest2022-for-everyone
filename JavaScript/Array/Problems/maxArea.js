[1, 8, 6, 2, 5, 4, 8, 3, 7];

/**
 * @param {number[]} height
 * @return {number}
 */

console.time("MAX");

var maxArea = (height) => {
  let ans = 0;
  i = 0;
  j = height.length - 1;
  while (i < j) {
    ans = Math.max(ans, Math.min(height[i], height[j]) * (j - i));
    height[i] <= height[j] ? i++ : j--;
  }
  return ans;
};
console.timeEnd("MAX");

console.log(maxArea([1, 8, 6, 2, 5, 4, 8, 5, 5, 5, 5, 5, 5, 5, 5, 5, 7]));
