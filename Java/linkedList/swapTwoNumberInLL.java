package linkedList;

public class swapTwoNumberInLL {
	
//  Definition for singly-linked list.
  public static class ListNode {
     int val;
      ListNode next;
      ListNode() {}
      ListNode(int val) { this.val = val; }
      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
  }
 
  public static void printLL(ListNode head) {
	  ListNode cur=head;
	  while(cur!=null) {
		  System.out.print(cur.val +" --> ");
		  cur=cur.next;
	  }
	  System.out.println("end");
  }
	
	
	    public static ListNode swapPairs(ListNode head) {
	        ListNode dummy = new ListNode(-1);
	        dummy.next = head;
	        ListNode prev=dummy;
	        while(prev.next !=null && prev.next.next !=null){
	            ListNode current=prev.next;
	            ListNode forward=current.next;
	            ListNode temp=forward.next;
	            
	            prev.next=forward;
	            forward.next=current;
	            current.next=temp;
	            
	            prev=current;
	        }
	        return dummy.next;
	        
	    }
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ListNode head=new ListNode(1);
		head.next=new ListNode(8);
		head.next.next=new ListNode(3);
		head.next.next.next=new ListNode(4);
		head.next.next.next.next=new ListNode(5);
		head.next.next.next.next.next=new ListNode(6);
		
		printLL(head);
		swapPairs(head);
		printLL(head);
	}

}
