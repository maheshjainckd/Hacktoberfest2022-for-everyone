

function twosum(nums, target) {
  const memo = {};
  for (let i = 0; i < nums.length; i++) {

    const needed = target - nums[i];
    console.log(needed)
    let index2 = memo[needed];
console.log("index2",index2,memo[needed],memo)
    if (index2 != null) {
      return [index2, i];
    } else {
      memo[nums[i]] = i;
    }
  }
}

console.log(twosum([ 11, 15,2, 7], 9));
