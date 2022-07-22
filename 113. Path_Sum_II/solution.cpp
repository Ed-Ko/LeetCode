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
    
    vector<vector<int>> ans;
    
    void recur(TreeNode* cur_node, vector<int> cur_path, int targetSum){
        
        cur_path.push_back(cur_node->val);
        
        if(cur_node->left != nullptr || cur_node->right != nullptr){
            if(cur_node->left != nullptr)
                recur(cur_node->left, cur_path, targetSum);
            if(cur_node->right != nullptr)
                recur(cur_node->right, cur_path, targetSum);
        }
            
        else{
            int sum = 0;
            for(int i = 0 ; i < cur_path.size() ; i++)
                sum += cur_path[i];
            if(sum == targetSum){
                vector<int> tmp;
                for(int i = 0 ; i < cur_path.size() ; i++)
                    tmp.push_back(cur_path[i]);
                ans.push_back(tmp);
            }
        }
        
        
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(root == nullptr)
            return ans;
        vector<int> start;
        recur(root, start, targetSum);
        return ans;
    }
};