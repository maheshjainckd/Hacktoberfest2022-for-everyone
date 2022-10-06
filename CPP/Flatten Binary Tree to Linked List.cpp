void flatten(Node *root)
    {
        //code here
        stack<Node*>st;
        st.push(root);
        while(!st.empty())
        {
            Node*curr=st.top();
            st.pop();
            if(curr!=NULL and curr->right!=NULL)
            {
                st.push(curr->right);
            }
            if(curr!=NULL and curr->left!=NULL)
            {
                st.push(curr->left);
            }
            if(!st.empty())
            {
                curr->right=st.top();
                curr->left=NULL;
            }
            
        }
    }
