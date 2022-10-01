   class Tuple {
    TreeNode node;
    int row;
    int col;
    Tuple (TreeNode node, int row, int col)    
    {
    this.node = node;
    this.row = row;
    this.col = col;    
    }
}
    public List<List<Integer>> verticalTraversal(TreeNode root) {
    List < List < Integer >> ans = new ArrayList <> ();   
    Queue <Tuple> q = new LinkedList (); //Queue required => level order trav...
    TreeMap <Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new TreeMap();
     q.add(new Tuple(root,0,0));
     while (!q.isEmpty())   
     {
         Tuple tuple = q.remove();
         TreeNode node = tuple.node;
         int row = tuple.row;
         int col = tuple.col;
         if (!map.containsKey(col))
             map.put(col, new TreeMap<>());
         if (!map.get(col).containsKey(row))
             map.get(col).put(row, new PriorityQueue());
         map.get(col).get(row).add(node.val); // adding in Priority Queue
         if (node.left != null)
             q.add(new Tuple(node.left, row+1, col-1));
         if (node.right != null)
             q.add(new Tuple(node.right, row+1, col+1));
     }  
     for (TreeMap<Integer, PriorityQueue<Integer>> innerTM : map.values())   
     {
         ans.add(new ArrayList<>());
         for (PriorityQueue<Integer> pq : innerTM.values())
         {
            while (!pq.isEmpty())
            {
                ans.get(ans.size()-1).add(pq.remove());
            }
         }
     }
     return ans;   
    }
