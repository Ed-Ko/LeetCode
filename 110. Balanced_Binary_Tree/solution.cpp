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
    
    int error = 0;
    
    int recur(TreeNode* cur_node){
        
        if(cur_node == nullptr)
            return 0;
        
        int left_h = 0;
        int right_h = 0;
        left_h = recur(cur_node->left);
        right_h = recur(cur_node->right);
        
        if(error)
            return 0;
        
        if(abs(left_h - right_h) > 1){
            error = 1;
            return 0;
        }
        return max(left_h, right_h) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        int buf_result = recur(root);
        if(error)
            return false;
        return true;
    }
};