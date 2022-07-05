/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int height = 0;
    
    queue<TreeNode*> node_queue;
    
    void BFS(){
        
        int find = 0;
        
        while(!node_queue.empty() && find == 0){
            
            height++;
            vector<TreeNode*> node_vec;
            
            while(!node_queue.empty()){
                node_vec.push_back(node_queue.front());
                node_queue.pop();
            }
            
            for(int i = 0 ; i < node_vec.size() ; i++){
                TreeNode* cur_node = node_vec[i];
                if(cur_node->left != nullptr)
                    node_queue.push(cur_node->left);
                if(cur_node->right != nullptr)
                    node_queue.push(cur_node->right);
                if(cur_node->left == nullptr && cur_node->right == nullptr){
                    find = 1;
                    break;
                }
            }
            
        }
        
        
    }
    
    int minDepth(TreeNode* root) {
        if(root != nullptr)
            node_queue.push(root);
        
        BFS();
        
        return height;
    }
};