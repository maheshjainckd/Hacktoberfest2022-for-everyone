class Solution {
    public LinkedList<Integer> a = new LinkedList<>(); 
    public LinkedList<Integer> aa = new LinkedList<>();
    public void addd(TreeNode p,LinkedList<Integer> a){
        if(p==null){
            a.add(-1);
            return;}
        a.add(p.val);
        addd(p.left,a);
        addd(p.right,a);
    }
    public boolean isSameTree(TreeNode p, TreeNode q) {
        addd(p,a); 
        addd(q,aa);
        if(a.equals(aa))
            return true; 
        return false;
    }
}
