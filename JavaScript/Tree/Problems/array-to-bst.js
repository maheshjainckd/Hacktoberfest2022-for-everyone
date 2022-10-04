function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
  @param {number[]} nums
  @return {TreeNode}
 */
var sortedArrayToBST = function (nums) {
  if (nums.length == 0) return null;
  if (nums.length == 1) return new TreeNode(nums[0], null, null);
  if (nums.length == 2)
    return new TreeNode(nums[1], sortedArrayToBST(nums.slice(0, 1)), null);
  let middle = Math.floor(nums.length / 2);
  return new TreeNode(
    nums[middle],
    sortedArrayToBST(nums.slice(0, middle)),
    sortedArrayToBST(nums.slice(middle + 1))
  );
};

console.log(sortedArrayToBST([-10, -3, 0, 5, 9]));
// output: [0,-3,9,-10,null,5]
