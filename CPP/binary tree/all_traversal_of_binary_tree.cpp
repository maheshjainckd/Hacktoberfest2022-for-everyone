#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int key;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value)
    {
        key = value;
        left = right = NULL;
    }
};

void levelOrderTraversal(TreeNode *root)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
    }
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->key << " ";
}

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(10);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(25);
    root->right->right = new TreeNode(30);

    inorder(root);
    cout << '\n';
    preorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    levelOrderTraversal(root);
    cout << '\n';
    return 0;
}
