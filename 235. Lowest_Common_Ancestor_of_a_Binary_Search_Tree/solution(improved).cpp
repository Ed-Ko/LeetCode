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
    
    TreeNode* search(TreeNode* cur_node, int p, int q){
        
        if(p <= cur_node->val && cur_node->val <= q)
            return cur_node;
        
        TreeNode* cur_return;
        
        if(p < cur_node->val && q < cur_node->val)
            cur_return = search(cur_node->left, p, q);
        else if(cur_node->val < p && cur_node->val < q)
            cur_return = search(cur_node->right, p, q);
        
        return cur_return;
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        int a = min(p->val, q->val);
        int b = max(p->val, q->val);
        
        return search(root, a, b);
        
    }
};