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
    
    vector<vector<int>> recur(vector<TreeNode*> node_list){
        
        vector<TreeNode*> next_layer;
        vector<vector<int>> return_vec;
        vector<int> tmp;
        
        if(node_list.size() == 1 && node_list[0] == nullptr)
            return return_vec;
            
        for(int i = 0 ; i < node_list.size() ; i++){
            if(node_list[i]->left != nullptr)
                next_layer.push_back(node_list[i]->left);
            if(node_list[i]->right != nullptr)
                next_layer.push_back(node_list[i]->right);
        }
        
        
        for(int i = 0 ; i < node_list.size() ; i++)
            tmp.push_back(node_list[i]->val);
        
        if(next_layer.size() != 0)
            return_vec = recur(next_layer);
        
        return_vec.push_back(tmp);
        return return_vec;
        
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<TreeNode*> tmp;
        tmp.push_back(root);
        return recur(tmp);
    }
};