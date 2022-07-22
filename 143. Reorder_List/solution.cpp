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
    void reorderList(ListNode* head) {
        
        ListNode* it = head;
        vector<ListNode*> node_list;
        while(it != nullptr){
            node_list.push_back(it);
            it = it->next;
        }
        
        int left = 0;
        int right = node_list.size() - 1;
        
        if(node_list.size() % 2 == 0){
            while(left < right){
                ListNode* next_left;
                ListNode* next_right;
                if(left + 1 < right){
                    next_left = node_list[left + 1];
                    next_right = node_list[right - 1];
                }
                else{
                    next_left = nullptr;
                    next_right = nullptr;
                }

                node_list[left]->next = node_list[right];
                node_list[right]->next = next_left;


                left++;
                right--;
            
            }
        }
        else{
            while(left <= right){
                ListNode* next_left;
                ListNode* next_right;
                
                if(left != right){
                    next_left = node_list[left + 1];
                    next_right = node_list[right - 1];
                    node_list[left]->next = node_list[right];
                    node_list[right]->next = next_left;
                }
                else
                    node_list[left]->next = nullptr;
                

                left++;
                right--;
                //cout << left << " " << right << endl;
            }
        }
        
        
        return;
        
        
    }
};