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
    
    unordered_set<int> dict;
    
    bool recur(TreeNode* cur_node, int target){
        
        
        if(cur_node == nullptr)
            return false;
    
        if(recur(cur_node->left, target))
            return true;    
        if(dict.count(target - cur_node->val))
            return true;
        
        dict.insert(cur_node->val);
        if(recur(cur_node->right, target))
            return true;
        return false;
    }
    
    bool findTarget(TreeNode* root, int k) {
        return recur(root, k);
    }
};