function TreeNode(val, left, right) {
  this.val = val === undefined ? 0 : val;
  this.left = left === undefined ? null : left;
  this.right = right === undefined ? null : right;
}

/**
 * @param {TreeNode} root
 * @return {void} Do not return anything, modify root in-place instead.
 */
var recoverTree = function (root) {
  const arr = [];
  const traverse = (r = root) => {
    if (!r) return;
    traverse(r.left);
    arr.push(r.val);
    traverse(r.right);
  };
  traverse();

  arr.sort((a, b) => a - b);
  let k = 0;
  const recover = (r = root) => {
    if (!r) return null;
    recover(r.left);
    r.val = arr[k++];
    recover(r.right);
  };
  recover();
  return root;
};
//input = [1,3,null,null,2]
//output = [3,1,null,null,2]
