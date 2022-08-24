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
        
        stack<int> st;
        
        ListNode* it = head;
        
        while(it != nullptr){
            st.push(it->val);
            it = it->next;
        }
        
        it = head;
        
        while(it != nullptr){
            if(st.top() == it->val)
                st.pop();
            else
                break;
            it = it->next;
        }
        
        return st.size() == 0 ? true : false;
        
    }
};