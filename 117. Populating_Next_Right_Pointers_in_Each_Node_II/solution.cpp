/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    void BFS(Node* root){
        
        if(root == nullptr)
            return;
        
        queue<Node*> q;
        int counter = 1;
        
        q.push(root);
        
        while(!q.empty()){
            
            int next_counter = 0;
            
            for(int i = 0 ; i < counter ; i++){
                
                Node* cur_node = q.front();
                q.pop();
                
                if(i < counter - 1)
                    cur_node->next = q.front();
                
                if(cur_node->left != nullptr){
                    q.push(cur_node->left);
                    next_counter++;
                }
                    
                if(cur_node->right != nullptr){
                    q.push(cur_node->right);
                    next_counter++;
                }
            }
            
            counter = next_counter;
            
        }
        
        return;
    }
    
    Node* connect(Node* root) {
        
        BFS(root);
        
        return root;
        
    }
};