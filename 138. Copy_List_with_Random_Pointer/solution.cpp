/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        map<int,int> find_random;
        map<Node*,int> old_random_list;
        vector<int> random_pos;
        map<int, Node*> random_list;
        
        Node* new_head = new Node(0);
        Node* new_buf = new_head;
        
        int i = 0;
        for(Node* it = head ; it != nullptr ; it = it->next){
            
            old_random_list[it] = i;
            i++;
            
            new_buf->next = new Node(it->val);
            new_buf = new_buf->next;
        }
        
        for(Node* it = head ; it != nullptr ; it = it->next){
            if(it->random == nullptr)
                random_pos.push_back(-1);
            else
                random_pos.push_back(old_random_list[it->random]);
        }
            
        
        i = 0;
        for(Node* it = new_head->next ; it != nullptr ; it = it->next){
            random_list[i] = it;
            i++;
        }
            
        
        new_buf = new_head->next;
        i = 0;
        for(auto it = new_head->next ; it != nullptr ; it = it->next){
            //cout << random_pos[i] << endl;
            if(random_pos[i] == -1)
                it->random = nullptr;
            else
               it->random = random_list[random_pos[i]];
            i++;
        }
            
        
        //for(auto it = new_head->next ; it != nullptr ; it = it->next)
        //    cout << it->val << " " << it->random->val << endl;
        
        return new_head->next;
        
    }
};