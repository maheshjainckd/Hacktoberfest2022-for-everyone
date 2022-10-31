package linkedList;

import java.util.HashMap;

public class createBinaryTreeWithInOrderTraversal {

	
//	  Definition for a binary tree node.
	  public class TreeNode {
	      int val;
	      TreeNode left;
	      TreeNode right;
	      TreeNode() {}
	      TreeNode(int val) { this.val = val; }
	      TreeNode(int val, TreeNode left, TreeNode right) {
	          this.val = val;
	          this.left = left;
	          this.right = right;
	      }
	  }
	 
	    HashMap<Integer, Integer> map=new HashMap<>();
	    int preIndex=0;
	    public TreeNode buildTree(int[] preorder, int[] inorder) {
	       for(int i=0; i<inorder.length; i++){
	           map.put(inorder[i], i);
	       }
	        return create(preorder,inorder,0,inorder.length-1);
	        
	    }
	     TreeNode create(int pre[],int in[], int s,int e){
	         if(s>e){
	             return null;
	         }
	         
	         TreeNode root=new TreeNode(pre[preIndex++]);
	         if(s==e){
	             return root;
	         }
	         int index=map.get(root.val);
	         root.left=create(pre,in,s,index-1);
	         root.right=create(pre,in ,index+1,e);
	         
	         return root;
	     }
	     
	     void printInorder(TreeNode root)
	     {
	         if (root == null)
	             return;
	  
	         /* first recur on left child */
	         printInorder(root.left);
	  
	         /* then print the data of node */
	         System.out.print(root.val + " ");
	  
	         /* now recur on right child */
	         printInorder(root.right);
	     }

	public static void main(String args[])
    {
		createBinaryTreeWithInOrderTraversal tree = new createBinaryTreeWithInOrderTraversal();
        int in[] = new int[] { 3,9,20,15,7 };
        int pre[] = new int[] {9,3,15,20,7};
        int len = in.length;
        TreeNode root = tree.buildTree( pre,in);
 
        // building the tree by printing inorder traversal
        System.out.println("Inorder traversal of constructed tree is : ");
        tree.printInorder(root);
    }
}
