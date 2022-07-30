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
    
    vector<TreeNode*> ans;
    
    void traversal(TreeNode* cur_node){
        
        if(cur_node == nullptr)
            return;
        
        ans.push_back(cur_node);
        
        if(cur_node->left != nullptr)
            traversal(cur_node->left);
        if(cur_node->right != nullptr)
            traversal(cur_node->right);
        
        return;
    }
    
    void flatten(TreeNode* root) {
        
        traversal(root);
        
        TreeNode* start = new TreeNode();
        TreeNode* it = start;
        for(int i = 0 ; i < ans.size() ; i++){
            it->right = ans[i];
            it->left = nullptr;
            it = it->right;
        }
        
        return;
    }
};