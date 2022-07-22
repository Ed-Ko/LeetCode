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
    
    TreeNode* BST(vector<int>& nums, int left, int right){
        
        int mid = (left + right) / 2;
        
        TreeNode* cur_node = new TreeNode(nums[mid]);
        
        if(left == right)
            return cur_node;
        if(left == right - 1){
            cur_node->right = new TreeNode(nums[right]);
            return cur_node;
        }
        
        cur_node->left = BST(nums, left, mid - 1);
        cur_node->right = BST(nums, mid + 1, right);
        
        return cur_node;
        
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        TreeNode* root = BST(nums, 0, nums.size() - 1);
        
        return root;
    }
};