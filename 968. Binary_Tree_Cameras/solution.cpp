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
    
    int ans = 0;
    
    int DFS(TreeNode* cur_node){
        
        if(cur_node == nullptr)
            return 1;
        
        int left_con = 1;
        int right_con = 1;
        if(cur_node->left != nullptr)
            left_con = DFS(cur_node->left);
        if(cur_node->right != nullptr)
            right_con = DFS(cur_node->right);
        
        if(left_con == 0 || right_con == 0){
            ans++;
            return 2;
        }
        
        if(left_con == 2 || right_con == 2)
            return 1;
        
        return 0;
        
    }
    
    int minCameraCover(TreeNode* root) {
        if(DFS(root) == 0)
            ans++;
        return ans;
    }
};