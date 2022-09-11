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
    
    bool DFS(TreeNode* left_node, TreeNode* right_node){
        
        if(left_node == nullptr && right_node == nullptr)
            return true;
        else if(left_node != nullptr && right_node != nullptr){
            if(left_node->val == right_node->val && DFS(left_node->right, right_node->left) && DFS(left_node->left, right_node->right))
                return true;
        }
        
        return false;
        
    }
    
    bool isSymmetric(TreeNode* root) {
        return DFS(root->left, root->right);;    
    }
};