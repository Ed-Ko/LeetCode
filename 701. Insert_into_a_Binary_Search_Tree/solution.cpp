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
    
    void insert(TreeNode* cur_node, int val){
        
        if(val < cur_node->val){
            if(cur_node->left != nullptr)
                insert(cur_node->left, val);
            else
                cur_node->left = new TreeNode(val);
        }
        else{
            if(cur_node->right != nullptr)
                insert(cur_node->right, val);
            else
                cur_node->right = new TreeNode(val);
        }
        return;
    }
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root != nullptr)
            insert(root, val);
        else
            root = new TreeNode(val);
        return root;
    }
};