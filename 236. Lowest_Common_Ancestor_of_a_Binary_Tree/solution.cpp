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
    int check = 0;
    TreeNode* recur(TreeNode* cur_node, TreeNode* p, TreeNode* q){
        
        TreeNode* empty_node = new TreeNode(INT_MIN);
        if(cur_node == nullptr)
            return empty_node;
        
        TreeNode* left_return = recur(cur_node->left, p, q);
        TreeNode* right_return = recur(cur_node->right, p, q);
        
        
        
        if(left_return->val != INT_MIN && right_return->val != INT_MIN){
            check = 1;
            return cur_node;
        }  
        
        if(cur_node == p || cur_node == q){
            if(left_return->val != INT_MIN || right_return->val != INT_MIN)
                check = 1;
            return cur_node;
        }
        
        if(left_return->val != INT_MIN)
            return left_return;
        else if(right_return->val != INT_MIN)
            return right_return;
        else
            return empty_node;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        
        return recur(root, p, q);
        
    }
};