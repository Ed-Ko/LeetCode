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
    void DFS(TreeNode* cur_node){
        if(cur_node != nullptr){
            if(cur_node->left != nullptr)
                DFS(cur_node->left);
            ans.push_back(cur_node->val);
            if(cur_node->right != nullptr)
                DFS(cur_node->right);
        }
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        DFS(root);
        return ans;
    }
};