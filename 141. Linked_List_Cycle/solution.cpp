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
    bool hasCycle(ListNode *head) {
        
        map<ListNode*,int> history;
        
        ListNode* it = head;
        while(it != nullptr){
            if(history.find(it) != history.end())
                return true;
            else
                history[it] = it->val;
            it = it->next;
        }
        return false;
    }
};