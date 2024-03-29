/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        
        ListNode pre = null;
        ListNode cur = head;
        ListNode tmp;
        
        while(!Objects.isNull(cur)){
            tmp = cur.next;
            cur.next = pre;
            pre = cur;
            cur = tmp;
        }
        
        return pre;
        
    }
}