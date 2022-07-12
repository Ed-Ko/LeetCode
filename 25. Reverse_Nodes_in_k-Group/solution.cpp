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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head == nullptr || k == 1)
            return head;
        
        ListNode* former = head;
        ListNode* latter = head;
        ListNode* cur_pre = nullptr;
        ListNode* next_former = nullptr;
        ListNode* ans = nullptr;
        
        while(latter != nullptr){
            int check = 1;
            for(int i = 0 ; i < k - 1 ; i++){
                cout << "latter : " << latter->val << endl;
                latter = latter->next;
                if(latter == nullptr){
                    check = 0;
                    break;
                }
            }
            if(!check)
                break;
            
                
            else{
                if(ans == nullptr)
                    ans = latter;
                if(cur_pre != nullptr)
                    cur_pre->next = latter;
                next_former = latter->next;
                ListNode* pre = next_former;
                ListNode* cur = former;
                ListNode* next_cur;
                while(pre != latter){
                    next_cur = cur->next;
                    cur->next = pre;
                    pre = cur;
                    cur = next_cur;
                }
                
            }
            
            //for(ListNode* it = latter ; it != nullptr ; it = it->next)
            //    cout << it->val << " " ;
            //cout << endl;
            
            
            //cout << pre->val << " " << latter->val << endl;
            
            /*
            ListNode* next_former = latter->next;
            ListNode* next_latter = latter->next;
            
            if(next_latter != nullptr){
                for(int i = 0 ; i < k - 1 ; i++){
                    if(next_latter->next == nullptr){
                        check = 0;
                        break;
                    }
                    next_latter = next_latter->next;
                }
                if(!check)
                    break;
            }
            */
            //cout << next_former->val << " " << next_latter->val << endl;
            
            cout << " ==== " << endl;
            cur_pre = former;
            former = next_former;
            latter = next_former;
        }
        
        return ans;
    }
};