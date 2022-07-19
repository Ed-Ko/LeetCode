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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* buf = new ListNode();
        buf->next = head;
        
        map<int,int> dict;
        
        for(ListNode* it = head ; it != nullptr ; it = it->next){
            if(dict.find(it->val) != dict.end())
                dict[it->val]++;
            else
                dict[it->val] = 1;
        }
        
        
        ListNode* left_node = buf;
        ListNode* cur_node = head;
        while(cur_node != nullptr){
            if(dict[cur_node->val] > 1){
                
                while(cur_node != nullptr && dict[cur_node->val] > 0){
                    dict[cur_node->val]--;
                    cur_node = cur_node->next;
                    if(cur_node != nullptr && cur_node->next != nullptr){
                        if(cur_node->val != cur_node->next->val && dict[cur_node->next->val] <= 1){
                            cur_node = cur_node->next;
                            break;
                        }
                            
                    }   
                }
                
                left_node->next = cur_node;
                left_node = cur_node;
                if(cur_node != nullptr)
                    cur_node = cur_node->next;
            }
            else{
                cur_node = cur_node->next;
                left_node = left_node->next; 
            }
            
        }
        
        return buf->next;
        
    }
};