function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {number[][]}
 */
var levelOrder = function (root) {
  let result = [];
  let queue = [];
  let temp = [];
  if (!root) return [];
  queue.push(root);
  queue.push(null);
  while (queue.length) {
    let node = queue.shift();
    if (node !== null) {
      temp.push(node.val);
      if (node.left) queue.push(node.left);
      if (node.right) queue.push(node.right);
    } else if (node == null) {
      if (queue.length) {
        queue.push(null);
      }
      result.push(temp);
      temp = [];
    }
  }
  return result;
};

// input = [3,9,20,null,null,15,7]
// output = [[3],[9,20],[15,7]]
