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
    bool isPalindrome(ListNode* head) {
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            if(fast->next != nullptr)
                fast = (fast->next)->next;
            else 
                break;
        }
        
        if(fast == nullptr){
            
            ListNode* it = slow;
            ListNode* prev = nullptr;
            
            while(it != nullptr){
                ListNode* next_node = it->next;
                it->next = prev;
                prev = it;
                it = next_node;
            }
            
            it = prev;
            ListNode* it2 = head;
            
            while(it != nullptr){
                if(it->val != it2->val)
                    return false;
                it = it->next;
                it2 = it2->next;
            }
            
            return true;
            
        }
        
        ListNode* it = slow->next;
        ListNode* prev = nullptr;
        
        while(it != nullptr){
            ListNode* next_node = it->next;
            it->next = prev;
            prev = it;
            it = next_node;
        }

        it = prev;
        ListNode* it2 = head;
        
        while(it != nullptr){
            if(it->val != it2->val)
                return false;
           
            
            it = it->next;
            it2 = it2->next;
        }
        
        return true;
        
    }
};