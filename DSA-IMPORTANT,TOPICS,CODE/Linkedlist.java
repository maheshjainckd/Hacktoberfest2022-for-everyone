import javax.print.event.PrintJobListener;

public class linkedlist {
    Node head; // for create and declared node
    private linkedlist.Node newNode;
    private int size;

    linkedlist() {
        this.size = 0;
    }

    class Node {

        String data;
        Node next; // means agla node so type hoga node
        // lets take a constructor

        Node(String data) {
            this.data = data;
            this.next = null;
            size++;
        }
    }

    // add - first, last
    public void addFirst(String data) {
        Node newNode = new Node(data);
        if (head == null) { // head = null then simply create new node will point to head and head become
                            // new node
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }

    // now addLast
    public void addLast(String data) {
        if (head == null) { // head = null then simply create new node will point to head and head become
                            // new node
            Node newNode = new Node(data);
            head = newNode;
            return;
        } // for travel linkedlist we should create a new node
        Node currNode = head;
        while (currNode.next != null) { // dont touch head in linkedlist we can touch and change of currentNode so that
                                        // we r traverse of currentNode towards linkedlist
            currNode = currNode.next;
        }

        currNode.next = newNode;

    }

    // print // important null smaller in JAVA --- NULL greater in C++.....
    public void printList() {
        if (head == null) {
            System.out.print("List is empty ");
            return;
        }
        Node currNode = head;
        while (currNode != null) {
            System.out.print(currNode.data + "-->");
            currNode = currNode.next;
        }
        System.out.println("NULL");
    }
    // for delete first and last we should make head at 2nd part since after that
    // first part is deleted forever
    // if i want to go for last then we should select second last so that last is
    // cut forever

    // deleteFirst
    public void deleteFirst() { // if list is empty then we can say corner case
        if (head == null) {
            System.out.print("The list is empty ");
        }
        size--;
        head = head.next; // this single line is enough for delete first
    }

    // delete last
    public void deleteLast() {
        if (head == null) {
            System.out.print("The list is empty ");
            return;
        }
        size--;
        if (head.next == null) {
            head = null;
            return;
        }
        Node secondLast = head;
        Node lastNode = head.next; // head.next=null -- lastNode = null
        while (lastNode.next != null) {
            lastNode = lastNode.next;
            secondLast = secondLast.next;
        }
        secondLast.next = null;
    }

    public int getSize() {
        return size;
    }

    public static void main(String[] args) {
        linkedlist k = new linkedlist();
        k.addFirst("a");
        k.addFirst("is");
        k.printList();

        k.addLast("list");
        k.printList();

        k.addFirst("this");
        k.printList();

        k.deleteFirst();
        k.printList();

        k.deleteLast();
        k.printList();

        System.out.println(k.getSize());
        k.addFirst("this");
        System.out.println(k.getSize());
    }

    public void reverseIterate() {
    }
}
