package linkedList;

public class removeNthNodeFromEnd {
	
	
//	  Definition for singly-linked list.
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
	  
	// Method --1
	    public static ListNode removeNthFromEnd1(ListNode head, int n){
	        
	        ListNode start =new ListNode(0);
	        ListNode pointer1=start, pointer2=start;
	        start.next=head;
	        int count=0;
	        
	        while(pointer1!=null){
	            pointer1=pointer1.next;
	            count++;
	        }
	        
	        for(int i=1;i<count-n;i++){
	            pointer2=pointer2.next;
	        
	        }

	            
	            pointer2.next=pointer2.next.next;
	        return start.next;
	    }

	// Method -- 2
	 
	     public static ListNode removeNthFromEnd2(ListNode head, int n) {
	         ListNode dummy=new ListNode(0);
	         ListNode slow=dummy, fast =dummy;
	          dummy.next=head;	        
	         for(int i=1;i<=n+1;i++){
	             fast=fast.next;

	         }
	         while(fast != null){
	             slow=slow.next;
	             fast=fast.next;
	         }
	         slow.next=slow.next.next;
	         return dummy.next;
	     }
	 

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode head=new ListNode(1);
		head.next=new ListNode(2);
		head.next.next=new ListNode(3);
		head.next.next.next=new ListNode(4);
		head.next.next.next.next=new ListNode(5);
		
		ListNode head2=new ListNode(1);
		head2.next=new ListNode(2);
		head2.next.next=new ListNode(3);
		head2.next.next.next=new ListNode(4);
		head2.next.next.next.next=new ListNode(5);
		
		int n=2;
		printLL(head);
		System.out.println("By using two pointer method : " );
		removeNthFromEnd1(head,n);
		printLL(head);
		System.out.println("By using slow fast pointer methos :");
		removeNthFromEnd2(head2,n);
		printLL(head2); 
	}

}
