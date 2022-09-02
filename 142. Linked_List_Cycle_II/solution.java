/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        
        ListNode slow = head;
        ListNode fast = head;
        ListNode enter = head;
        
        while(!Objects.isNull(fast) && !Objects.isNull(fast.next)){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                while(slow != enter){
                    enter = enter.next;
                    slow = slow.next;
                }
                return enter;
            }
        }
        
        return null;
        
    }
}