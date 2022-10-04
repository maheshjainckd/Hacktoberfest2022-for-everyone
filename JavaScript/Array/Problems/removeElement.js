var removeElement = function (nums, val) {
  let len = nums.length;
  if (nums.length === 0) return 0;
  let p1 = 0;
  for (let p2 = 0; p2 < nums.length; p2++) {
    console.log(nums[p2], "checkkk", p2,p1);

    // console.log(nums, nums.length);

    if (nums[p2] != val) {
    //   console.log(nums[p2],nums[p1], "checkkk", p2);
    //   p1++;
      nums[p1++]=nums[p2];
      console.log(nums)
    }
  }
  return p1 ;
};

console.error(removeElement([0, 1, 2, 2, 3, 0, 4, 2], 2));
[].splice();
