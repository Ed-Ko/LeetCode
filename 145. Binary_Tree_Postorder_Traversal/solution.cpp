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
    
    vector<int> traversal(TreeNode* cur_node){
        
        if(cur_node == nullptr){
            vector<int> empty_vec;
            return empty_vec;
        }
        
        vector<int> cur_list;
        
        
        vector<int> left_return = traversal(cur_node->left);
        vector<int> right_return = traversal(cur_node->right);
        if(left_return.size() > 0)
            cur_list.insert(cur_list.end(), left_return.begin(), left_return.end());
        if(right_return.size() > 0)
            cur_list.insert(cur_list.end(), right_return.begin(), right_return.end());
        
        
        cur_list.push_back(cur_node->val);
        
        return cur_list;
        
        
    }
    
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> start;
        return traversal(root);
    }
};