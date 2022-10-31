// below code shows the implementation of level order traversal of a binary tree using iterative method
void levelorder(node*root){
  queue<node*> q;
  q.push(root);
  while(!q.empty()){
    node *temp = q.front();
    cout<<temp->data<<" ";
    q.pop();
    
    if(temp->left) q.push(temp->left);
    if(temp->right) q.push(temp->right);
  }
}
