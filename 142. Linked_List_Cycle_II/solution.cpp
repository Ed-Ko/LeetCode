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
        
        map<ListNode*,int> history;
        
        ListNode* it = head;
        int idx_count = 0;
        while(it != nullptr){
            if(history.find(it) != history.end())
                return it;
            else{
                history[it] = idx_count;
                idx_count++;
            }
                
            it = it->next;
        }
        return nullptr;
        
    }
};