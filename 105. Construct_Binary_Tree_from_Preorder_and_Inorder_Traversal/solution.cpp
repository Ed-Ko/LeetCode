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
    
    TreeNode* recur(int pre_idx, int in_idx, int end_idx, vector<int>& preorder, vector<int>& inorder){
        
        if(pre_idx > preorder.size() - 1 || in_idx > end_idx)
            return nullptr;
        
        TreeNode* cur_node = new TreeNode(preorder[pre_idx]);
        
        int next_parent = 0;
        for(int i = in_idx ; i <= end_idx ; i++){
            if(inorder[i] == preorder[pre_idx]){
                next_parent = i;
                break;
            }
        }
        //cout << cur_node->val << " : " << in_idx << " " << next_parent - 1 << endl;
        cur_node->left = recur(pre_idx + 1, in_idx, next_parent - 1, preorder, inorder);
        cur_node->right = recur(pre_idx + next_parent - in_idx + 1, next_parent + 1, end_idx, preorder, inorder);
        
        
        //cout << "return node : " << cur_node->val << endl;
        return cur_node;
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        TreeNode* ans;
        if(preorder.size() == 1)
            ans = new TreeNode(preorder[0]);
        else
            ans = recur(0, 0, preorder.size() - 1, preorder, inorder);
        
        return ans;
        
    }
};