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
    public ListNode deleteDuplicates(ListNode head) {
        
        ListNode it = head;
        ListNode pre_head = new ListNode();
        ListNode new_start = pre_head;
        pre_head.next = head;
        
        if(Objects.isNull(head))
            return head;
        
        while(!Objects.isNull(it)){
            
            ListNode left = it;
            ListNode right = it.next;
            
            while(!Objects.isNull(right) && right.val == left.val)
                right = right.next;
            
            if(right != left.next){
                pre_head.next = right;
                it = right;
            }
            else{
                it = it.next;
                pre_head = pre_head.next;
            }
        }
        
        
       return new_start.next; 
        
    }
}