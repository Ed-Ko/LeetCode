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

    
    TreeNode* prun(TreeNode* cur_node){
        
        if(cur_node != nullptr){
            cur_node->left = prun(cur_node->left);
            cur_node->right = prun(cur_node->right);

            if(!cur_node->left && !cur_node->right && cur_node->val == 0)
                return nullptr;
        }
        
        return cur_node;
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        return prun(root);;
    }
};