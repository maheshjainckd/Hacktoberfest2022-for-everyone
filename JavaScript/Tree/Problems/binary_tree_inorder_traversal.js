function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var inorderTraversal = function (root) {
  let arr = [],
    stack = [],
    node = root;
  while (true) {
    if (node) {
      stack.push(node);
      node = node.left;
    } else {
      if (stack.length == 0) break;
      node = stack.pop();
      arr.push(node.val);
      node = node.right;
    }
  }
  return arr;
};

// input = [1,null,2,3]
//  1
//   \
//    2
//   /
//  3
// Output: [1,3,2]
