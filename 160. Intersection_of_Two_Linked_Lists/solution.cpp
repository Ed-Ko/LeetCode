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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        map<ListNode*,int> search_list;
        
        
        ListNode* it = headA;
        int i = 0;
        while(it != nullptr){
            search_list[it] = i;
            i++;
            it = it->next;
        }
        
        it = headB;
        while(it != nullptr){
            if(search_list.find(it) != search_list.end())
                return it;
            it = it->next;
        }
        
        return nullptr;
    }
};