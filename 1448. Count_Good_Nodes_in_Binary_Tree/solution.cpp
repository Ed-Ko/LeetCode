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
    
    int DFS(TreeNode* cur_node, int cur_num){
        
        if(cur_node == nullptr)
            return 0;
        
        int tmp_res = 0;
        
        int next_num = cur_num;
        if(cur_node->val >= cur_num){
            next_num = cur_node->val;
            tmp_res++;
        }
        
        return tmp_res + DFS(cur_node->left, next_num) + DFS(cur_node->right, next_num);
        
    }
    
    int goodNodes(TreeNode* root) {
        
        return DFS(root, root->val);
        
    }
};