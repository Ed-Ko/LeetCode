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
    
    TreeNode* search(TreeNode* cur_node, int val){
        
        if(cur_node->val == val)
            return cur_node;
        
        TreeNode* left_ret = nullptr;
        TreeNode* right_ret = nullptr;
        if(cur_node->left != nullptr)
            left_ret = search(cur_node->left, val);
        if(cur_node->right != nullptr)
            right_ret = search(cur_node->right, val);
        
        return left_ret != nullptr ? left_ret : right_ret;
        
    }
    
    TreeNode* searchBST(TreeNode* root, int val) {
        return search(root, val);
    }
};