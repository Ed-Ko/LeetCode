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
    ListNode* partition(ListNode* head, int x) {
        
        if(head == nullptr)
            return head;
        
        
        ListNode* cur_node = head;
        ListNode* ans = new ListNode();
        
        int first_idx = -1;
        vector<int> larger;
        vector<int> smaller;
        while(cur_node != nullptr){
            if(cur_node->val >= x)
                larger.push_back(cur_node->val);
            else
                smaller.push_back(cur_node->val);
            cur_node = cur_node->next;
        }
        
        ListNode* it = ans;
        
        for(int i = 0 ; i < smaller.size() ; i++){
            ans->next = new ListNode(smaller[i]);
            ans = ans->next;
        }
        for(int i = 0 ; i < larger.size() ; i++){
            ans->next = new ListNode(larger[i]);
            ans = ans->next;
        }
        
        
        return it->next;
        
    }
};