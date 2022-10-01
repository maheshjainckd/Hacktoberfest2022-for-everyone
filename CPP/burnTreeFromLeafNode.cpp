// C++ code to implement the approach by Kshitiz Pratap Singh

#include <bits/stdc++.h>
using namespace std;

// Structure of a tree node
struct Node {
	int key;
	struct Node* left;
	struct Node* right;
	Node(int k)
	{
		key = k;
		left = right = NULL;
	}
};

int res = 0;
// Function to find the time for the tree to burn
int burnTime(Node* root, int leaf, int& dist)
{
	if (root == NULL)
		return 0;
	if (root->key == leaf) {
		dist = 0;
		return 1;
	}
	int ldist = -1, rdist = -1;
	int lh = burnTime(root->left, leaf, ldist);
	int rh = burnTime(root->right, leaf, rdist);

	if (ldist != -1) {
		dist = ldist + 1;
		res = max(res, dist + rh);
	}
	else if (rdist != -1) {
		dist = rdist + 1;
		res = max(res, dist + lh);
	}
	return max(lh, rh) + 1;
}

// Driver code
int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->left->left->left = new Node(8);
	root->left->right->left = new Node(9);
	root->left->right->right = new Node(10);
	root->left->right->left->left = new Node(11);

	int dist = -1;
	int target = 11;

	burnTime(root, target, dist);

	cout << res;
	return 0;
}

//         	   1
//         /      \          
//        2        3
//      /   \     /
//     4     5   6 
//    /     / \
//   8     9   10
//        /
//       11