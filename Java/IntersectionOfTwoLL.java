/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        HashSet<ListNode> h1 = new HashSet<>();
        while(headA != null){
            h1.add(headA);
            headA = headA.next;
        }
        while(headB != null){
            if(h1.contains(headB)) return headB;
            h1.add(headB);
            headB = headB.next;
        }
        return null;
        
    }
}
