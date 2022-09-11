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
    
    void invert(TreeNode* cur_node){
        
        if(cur_node->left == nullptr && cur_node->right == nullptr)
            return;
        
        if(cur_node->left != nullptr)
            invert(cur_node->left);
        if(cur_node->right != nullptr)
            invert(cur_node->right);
        
        TreeNode* buf = cur_node->left;
        cur_node->left = cur_node->right;
        cur_node->right = buf;
        
        return;
    }
    
    
    TreeNode* invertTree(TreeNode* root) {
        if(root != nullptr)
            invert(root);
        return root;
    }
};