package linkedList;

public class AddTwoNumberInLL {
	
//	  Definition for singly-linked list.
	  public static class ListNode {
	      int val;
	      ListNode next;
	      ListNode() {}
	      ListNode(int val) { this.val = val; }
	      ListNode(int val, ListNode next) { this.val = val; this.next = next; }
	  }
	 
	  static void printLL(ListNode head) {
		  ListNode cur=head;
			while(cur!=null) {
				System.out.print(cur.val +" --> ");
				cur=cur.next;
			}
			System.out.println("end");
		}
	
	     public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
	        ListNode temp = new ListNode();
	        ListNode a1,a2,a3;
	        a1=l1;
	        a2=l2;
	        a3=temp;
	        int carry=0,num;
	        while(a1!=null && a2!=null)
	        {
	            num=a1.val+a2.val+carry;
	            carry=num/10;
	            a1=a1.next;
	            a2=a2.next;
	            ListNode x = new ListNode();
	            x.val = num%10;
	            a3.next = x;
	            a3 = a3.next;
	        }
	        while(a1!=null)
	        {
	            num = a1.val+carry;
	            carry = num/10;
	            a1=a1.next;
	            ListNode x = new ListNode();
	            x.val = num%10;
	            a3.next = x;
	            a3 = a3.next;
	        }
	        while(a2!=null)
	        {
	            num = a2.val+carry;
	            carry = num/10;
	            a2=a2.next;
	            ListNode x = new ListNode();
	            x.val = num%10;
	            a3.next = x;
	            a3 = a3.next;
	        }
	        if(carry != 0)
	        {
	            ListNode x = new ListNode();
	            x.val = carry;
	            a3.next = x;
	            a3=a3.next;
	        }
	        a3.next = null;
	       return temp.next;
	    }
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListNode l1=new ListNode(2);
		l1.next=new ListNode(4);
		l1.next.next = new ListNode(3);
		
		
		ListNode l2=new ListNode(5);
		l2.next=new ListNode(6);
		l2.next.next=new ListNode(4);
		
		printLL(l1);
		printLL(l2);
		ListNode result=addTwoNumbers(l1,l2);
		
		printLL(result);
		
	}

}
