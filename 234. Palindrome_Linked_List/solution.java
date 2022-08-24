
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
    public boolean isPalindrome(ListNode head) {
        
        Stack<Integer> st = new Stack<Integer>();
        
        ListNode it = head;
        
        while(!Objects.isNull(it)){
            st.push(it.val);
            if(!Objects.isNull(it.next))
                it = it.next;
            else
                break;
        }
        
        it = head;
        
        while(!Objects.isNull(it)){
            if(it.val == st.peek())
                st.pop();
            else
                break;
            if(!Objects.isNull(it.next))
                it = it.next;
            else
                break;
        }
        
        return st.empty();
        
    }
}