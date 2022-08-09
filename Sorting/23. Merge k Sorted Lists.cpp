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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        vector<int> cand;
        
        if(lists.size() == 0)
            return nullptr;
        
        for(int i = 0 ; i < lists.size() ; i++){
            ListNode* cur_head = lists[i];
            while(cur_head != nullptr){
                cand.push_back(cur_head->val);
                cur_head = cur_head->next;
            }
        }

        sort(cand.begin(), cand.end());
        
        if(cand.size() == 0)
            return nullptr;
        
        ListNode* new_head = new ListNode();
        ListNode* cur = new_head;
        for(int i = 0 ; i < cand.size() ; i++){
            cur->next = new ListNode(cand[i]);
            cur = cur->next;
        }
        
        
        return new_head->next;
    }
};