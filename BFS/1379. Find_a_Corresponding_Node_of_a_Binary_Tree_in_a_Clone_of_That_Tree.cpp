/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    queue<TreeNode*> node_queue;
    TreeNode* ans;
    
    TreeNode* BFS(TreeNode* target_node){
        
        
        
        while(!node_queue.empty()){
            TreeNode* cur_node = node_queue.front();
            node_queue.pop();
            
            if(cur_node->val == target_node->val)
                return cur_node;
            else{
            
                if(cur_node->left != nullptr)
                    node_queue.push(cur_node->left);

                if(cur_node->right != nullptr)
                    node_queue.push(cur_node->right);
            
            }
            
        }
        
        return ans;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        node_queue.push(cloned);
        ans = BFS(target);
        return ans;
    }
};