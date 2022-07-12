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
    
    vector<int> recur(vector<int> ans, TreeNode* cur_node, int cur_level){
        
        if(cur_node == nullptr)
            return ans;
        
        if(ans.size() == cur_level)
            ans.push_back(cur_node->val);
        
        ans = recur(ans, cur_node->right, cur_level + 1);
        ans = recur(ans, cur_node->left, cur_level + 1);
        return ans;
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        TreeNode* cur_node = root;
        
        ans = recur(ans, root, 0);
        
        return ans;
    }
};