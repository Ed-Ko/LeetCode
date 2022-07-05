/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        
        int list_len = 0;
        ListNode* buf = head;
        while(buf != nullptr){
            list_len++;
            buf = buf->next;
        }
        
        if(list_len == 1)
            return nullptr;
        
        
        ListNode* cur = head;
        int pre_idx = list_len - n - 1;
        if(pre_idx >= 0){   
            for(int i = 0 ; i < pre_idx; i++)
                cur = cur->next;
            cur->next = cur->next->next;
        }
        else
            head = head->next;
        
        
        return head;
    }
};