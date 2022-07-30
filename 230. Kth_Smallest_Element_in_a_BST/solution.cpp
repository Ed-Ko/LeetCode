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
    
    vector<int> ans;
    
    void traversal(TreeNode* cur_node){
        
        
        
        if(cur_node->left != nullptr)
            traversal(cur_node->left);
        if(cur_node != nullptr)
            ans.push_back(cur_node->val);
        if(cur_node->right != nullptr)
            traversal(cur_node->right);
        
        return;
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        
        traversal(root);
        
        return ans[k - 1];
        
    }
};