const nums = [5, 7, 7, 8, 8, 10];
const target = 8;

var searchRange = function (nums, target) {
  let ans = [];

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] === target) {
      ans.push(i);
      continue;
    }
  }
  const ansLen = ans.length;
  if (ansLen < 1) {
    ans.push(-1, -1);
  } else if (ansLen === 1) {
    ans.push(ans[0]);
  } else if (ansLen > 2) {
    ans = [ans[0], ans[ansLen - 1]];
  }
  return ans;
};
