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
    
    vector<int> ans;
    
    void DFS(Node* cur_node){
        
        ans.push_back(cur_node->val);
        
        for(int i = 0 ; i < cur_node->children.size() ; i++){
            if(cur_node->children[i] != nullptr)
                DFS(cur_node->children[i]);
        }
        
        return;
    }
    
    vector<int> preorder(Node* root) {
        
        if(root == nullptr)
            return {};
        
        DFS(root);
        return ans;
    }
};