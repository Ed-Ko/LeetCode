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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(left == right)
            return head;
        
        ListNode* buf = new ListNode();
        buf->next = head;
        ListNode* left_node = buf;
        ListNode* right_node = head;
        
        for(int i = 0 ; i < left - 1 ; i++)
            left_node = left_node->next;
        
        for(int i = 0 ; i < right ; i++)
            right_node = right_node->next;
        
        ListNode* pre_node = left_node;
        ListNode* cur_node = left_node->next;
        
        while(cur_node != right_node){
            ListNode* next_node = cur_node->next;
            if(pre_node == left_node)
                cur_node->next = right_node;
            else
                cur_node->next = pre_node;
            //cout << cur_node->val << " " << pre_node->val << endl;
            pre_node = cur_node;
            cur_node = next_node;
        }
        
        
        
        if(left == 1){
            buf->next = pre_node;
        }
        else{
            left_node->next->next = right_node;
            left_node->next = pre_node;
        }
            
        ListNode* it = buf->next;
        while(it != nullptr){
            //cout << it->val << " ";
            it = it->next;
        }
        
        //cout << left_node->val << " === " << pre_node->val << " === " << cur_node->val << " === " << right_node->val << endl;
        
        
        return buf->next;
    }
};