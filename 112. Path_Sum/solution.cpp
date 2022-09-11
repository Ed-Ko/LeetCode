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
    
    bool ans = false;
    
    void DFS(TreeNode* cur_node, int target, int cur_sum){
        
        if(cur_sum + cur_node->val == target && cur_node->left == nullptr && cur_node->right == nullptr){
            ans = true;
            return;
        }
                
        if(cur_node->left != nullptr)
            DFS(cur_node->left, target, cur_sum + cur_node->val);
        if(cur_node->right != nullptr && ans == false)
            DFS(cur_node->right, target, cur_sum + cur_node->val);
        
        return;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root != nullptr)
            DFS(root, targetSum, 0);
        return ans;
    }
};