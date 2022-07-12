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
    
    
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(root1 == nullptr && root2 == nullptr)
            return nullptr;
        else if(root1 == nullptr)
            return root2;
        else if(root2 == nullptr)
            return root1;
        
        int value = root1->val + root2->val;
        TreeNode* new_node = new TreeNode(value);
        cout << new_node->val << endl;
        
        TreeNode* left_node = mergeTrees(root1->left, root2->left);
        new_node->left = left_node;
        
        TreeNode* right_node = mergeTrees(root1->right, root2->right);
        new_node->right = right_node;
        
        return new_node;

      
    }
};