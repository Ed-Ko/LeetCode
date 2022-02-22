#include<cstdio>
#include<cstdlib>
#include<vector>
#include<iostream>
#include<map>
#include<algorithm>

using namespace std;



class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* cur = ans;
        int add=0;
        int carry=0;
        while(1){
            if(l1 != nullptr && l2 != nullptr){
                add = (l1->val + l2->val + carry) % 10;
                carry = (l1->val + l2->val + carry) / 10;
                ListNode* newnode = new ListNode(add);
                cur->next = newnode;
                cur = cur->next;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if(l1 == nullptr && l2 != nullptr){
                add = (l2->val + carry) % 10;
                carry = (l2->val + carry) / 10;
                ListNode* newnode = new ListNode(add);
                cur->next = newnode;
                cur = cur->next;
                l2 = l2->next;
            }
            else if(l1 != nullptr && l2 == nullptr){
                add = (l1->val + carry) % 10;
                carry = (l1->val + carry) / 10;
                ListNode* newnode = new ListNode(add);
                cur->next = newnode;
                cur = cur->next;
                l1 = l1->next;
            }
            
            if(l1 == nullptr && l2 == nullptr){
                if(carry != 0){
                    ListNode* newnode = new ListNode(carry);
                    cur->next = newnode;
                }
                break;
            }
                
            
        }
        return ans->next;
    }
};