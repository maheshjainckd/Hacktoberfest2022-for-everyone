package linkedList;

import org.w3c.dom.Node;

public class MergeTwoSortedLinkedList {
	
	static class node {
		int data;
		node next;
		public node(int data) {
			this.data=data;
		}
	}
	static void printLL(node head) {
		node cur=head;
		while(cur!=null) {
			System.out.print(cur.data +" --> ");
			cur=cur.next;
		}
		System.out.println("end");
	}
	
	
	public static node mergeLinkedList(node head1,node head2) {
		node head=null,tail=null;
		node a=head1, b=head2;
		
		if(a==null) return b;
		if(b==null) return a;
		
		if(a.data<=b.data) {
			head=a;
			tail=a;
			a=a.next;
		}else {
			head=b;
			tail=b;
			b=b.next;
		}
		
		while(a!=null && b!=null) {
			if(a.data < b.data) {
				tail.next=a;
				tail=a;
				a=a.next;
				
			}else {
				tail.next=b;
				tail=b;
				b=b.next;
			}
		}
		
		if(a==null) tail.next=b;
		if(b==null) tail.next=a;
		return head;
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		node head1 =new node(2);
		head1.next=new node(3);
		head1.next.next = new node(6);
		head1.next.next.next=new node(7);
		
		node head2=new node(1);
		head2.next=new node(4);
		head2.next.next=new node(5);
		head2.next.next.next=new node(8);
		head2.next.next.next.next=new node(9);
		head2.next.next.next.next.next= new node(10);
		
		printLL(head1);
		printLL(head2);
		node SortedLinkedList=mergeLinkedList(head1,head2);
		
		printLL(SortedLinkedList);
		

	}

}
