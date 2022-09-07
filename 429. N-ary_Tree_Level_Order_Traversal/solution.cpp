/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    
    vector<vector<int>> ans;
    
    void traverse(Node* root){
        
        queue<Node*> q;
        q.push(root);
        
        int counter = 1;
        while(!q.empty()){
            
            vector<int> cur_vec;
            
            int next_counter = 0;
            for(int i = 0 ; i < counter ; i++){
                Node* cur_node = q.front();
                q.pop();
                
                cur_vec.push_back(cur_node->val);
                
                for(int j = 0 ; j < cur_node->children.size() ; j++){
                    if(cur_node->children[j] != nullptr){
                        q.push(cur_node->children[j]);
                        next_counter++;
                    }
                }
            }
            
            ans.push_back(cur_vec);
            counter = next_counter;
        }
        
        return;
        
    }
    
    vector<vector<int>> levelOrder(Node* root) {
        
        if(root != nullptr)
            traverse(root);
        return ans;
        
    }
};