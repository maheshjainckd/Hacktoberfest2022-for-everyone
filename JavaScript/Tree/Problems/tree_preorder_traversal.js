var Tree = function () {
  this.root = null;
};

Tree.prototype.insert = function (node, data) {
  if (node == null) {
    node = new Node(data);
  } else if (data < node.data) {
    node.left = this.insert(node.left, data);
  } else {
    node.right = this.insert(node.right, data);
  }

  return node;
};

var Node = function (data) {
  this.data = data;
  this.left = null;
  this.right = null;
};

function preOrder(root) {
  if (root != null) {
    process.stdout.write(`${root.data} `);
    preOrder(root.left);
    preOrder(root.right);
  }
}

// input
// 1
//  \
//   2
//  /
// 3
// output = 1 2 3
