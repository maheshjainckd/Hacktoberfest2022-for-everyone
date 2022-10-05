class Node {
    constructor (val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class BinarySearchTree {
    constructor () {
        this.root = null;
    }

    insert(val) {
        const newNode = new Node(val);

        if (this.root === null) {
            this.root = newNode;
            return newNode;
        }

        let current = this.root;

        while (current) {
            if (current.val !== val) {
                if (current.val > val) {
                    if (current.left !== null) {
                        current = current.left;
                    } else {
                        current.left = newNode;
                        return current;
                    }               
                } else {
                    if (current.right !== null) {
                        current = current.right;
                    } else {
                        current.right = newNode;
                        return current;
                    }    
                }
            } else {
                return null;
            }
        }
    }

    search(val) {
        if (this.root === null) {
            return false;
        }

        let current = this.root;

        while (current) {
            if (current.val === val) {
                return current;
            } else {
                if (current.val > val) {
                    current = current.left;
                } else {
                    current = current.right;
                }
            }
        }

        return false;
    }
}

const bst = new BinarySearchTree();

bst.insert(5);
bst.insert(5);
bst.insert(4);
bst.insert(3);

bst.insert(6);
bst.insert(8);
bst.insert(7);

bst.search(1);

console.log('bst', bst.search(3));