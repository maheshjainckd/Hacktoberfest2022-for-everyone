
var threeSum = function (nums) {
  var result = [];
  var newd = [];
  nums.sort((a,b)=>a-b);

  for (var i = 0; i < nums.length; i++) {
    if (i > 0 && nums[i] === nums[i - 1]) continue;
    
    const target= -nums[i];
    let left = i + 1;
    let right = nums.length - 1;
    while (left < right) {
         if (nums[left] + nums[right] < target) {
            left++;
        }  if (nums[left] + nums[right] > target) {
            right--;
        }
        else if (nums[left] + nums[right] === target) {
            result.push([nums[i], nums[left], nums[right]]);
            while ( nums[left] === nums[left + 1]) left++;
            while ( nums[right] === nums[right - 1]) right--;
            left++;
            right--;
        } 
    }
  }

  return result;
};

console.log(threeSum([-1, 0, 1, 2, -1, -4]));
