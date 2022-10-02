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
    
    vector<int> vec;
    
    void recur(TreeNode* cur_node){
        
        if(cur_node->left != nullptr)
            recur(cur_node->left);
        vec.emplace_back(cur_node->val);
        if(cur_node->right != nullptr)
            recur(cur_node->right);
        return;
    }
    
    bool findTarget(TreeNode* root, int k) {
        
        recur(root);
        
        unordered_set<int> dict;
        
        for(int i = 0 ; i < vec.size() ; i++){
            if(dict.count(k - vec[i]))
                return true;
            dict.insert(vec[i]);
        }
        return false;
    }
};