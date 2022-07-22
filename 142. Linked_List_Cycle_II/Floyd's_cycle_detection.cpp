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
        ListNode* inter = NULL;
        while(fast!= NULL && fast->next !=NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                inter = slow;
                break;
            }
        }
        ListNode* idx = head;
        if(inter != NULL)
        {
            while(idx != inter)
            {
                idx = idx->next;
                inter = inter->next;
            }
        }
        return (inter != NULL) ? idx: NULL;
    }
};