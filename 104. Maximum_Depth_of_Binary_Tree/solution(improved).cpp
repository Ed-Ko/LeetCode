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
    
    
    void BFS(TreeNode* root){
        
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        
        int counter = 1;
        while(!node_queue.empty()){
            
            height++;
            int next_counter = 0;   
            
            for(int i = 0 ; i < counter ; i++){
                TreeNode* cur_node = node_queue.front();
                node_queue.pop();
                if(cur_node->left != nullptr){
                    node_queue.push(cur_node->left);
                    next_counter++;
                }
                if(cur_node->right != nullptr){
                    node_queue.push(cur_node->right);
                    next_counter++;
                }
                    
            }
            
            counter = next_counter;
            
        }
        
        
    }
    
    int maxDepth(TreeNode* root) {
        
        if(root != nullptr)
            BFS(root);
        
        return height;
        
    }
};