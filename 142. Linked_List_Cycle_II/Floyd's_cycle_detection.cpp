/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* enter = head;
        
        while(fast != nullptr && fast->next != nullptr && slow != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(enter != slow){
                    slow = slow->next;
                    enter = enter->next;
                }
                return enter;
            }
                
        }
        
        return nullptr;
        
    }
};