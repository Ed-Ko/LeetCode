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
    
    
    ListNode* swapPairs(ListNode* head) {
        
        if(head == nullptr)
            return head;
        if(head->next == nullptr)
            return head;
        
        ListNode* former = head;
        ListNode* latter = head->next;
        ListNode* ans = latter;
        
        while(former != nullptr && latter != nullptr){
            
            ListNode* next_former;
            ListNode* next_latter;
            
            if(former->next->next != nullptr)
                next_former = former->next->next;
            else
                next_former = nullptr;
            
            if(latter->next != nullptr)
                next_latter = latter->next->next;
            else
                next_latter = nullptr;
            
            if(next_latter == nullptr)
                former->next = next_former;
            else
                former->next = next_latter;
            latter->next = former;
            
            //cout << former->val << " " << latter->val << endl;
            //cout << former->next->val << " " << latter->next->val << endl;
            //cout << next_former->val << " " << next_latter->val << endl;
            //cout << " === " << endl;
            former = next_former;
            latter = next_latter;
            
        }
        
        return ans;
    }
};