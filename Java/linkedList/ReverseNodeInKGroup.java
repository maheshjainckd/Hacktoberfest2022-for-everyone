package linkedList;

public class ReverseNodeInKGroup {
	
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
	


    public static ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null || k == 1) {
            return head;
        }

        ListNode curr = head, prev = null, next = null;
        int count = 0;
        while (count < k && curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        head.next = reverseKGroup(next, k);
        
        if(count < k) {
            return reverseKGroup(prev, count);
        }

        return prev;
    }


	public static void main(String[] args) {
		// TODO Auto-generated method stub

		ListNode head=new ListNode(1);
		head.next=new ListNode(2);
		head.next.next=new ListNode(3);
		head.next.next.next=new ListNode(4);
		head.next.next.next.next=new ListNode(5);
		
		printLL(head);
		int k=2;
		reverseKGroup(head, k);
		printLL(head);
	}

}
