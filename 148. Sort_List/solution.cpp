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
    
    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr)
            return nullptr;
        
        ListNode* cur_node = head;
        vector<int> val;
        while(cur_node != nullptr){
            val.push_back(cur_node->val);
            cur_node = cur_node->next;
        }
        
        sort(val.begin(), val.end());
        
        ListNode* ans = new ListNode();   
        ListNode* it = ans;
        for(int i = 0 ; i < val.size() ; i++){
            it->next = new ListNode(val[i]);
            it = it->next;
        }
        
        return ans->next;
    }
};