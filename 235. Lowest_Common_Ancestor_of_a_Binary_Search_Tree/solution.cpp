/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    vector<TreeNode*> p_vec;
    vector<TreeNode*> q_vec;
    
    vector<TreeNode*> search(TreeNode* cur_node, int target){
        
        if(cur_node->val == target){
            vector<TreeNode*> tmp;
            tmp.push_back(cur_node);
            return tmp;
        }
            
        
        vector<TreeNode*> cur_return;
        vector<TreeNode*> tmp;
        cur_return.push_back(cur_node);
        if(cur_node->val > target)
            tmp = search(cur_node->left, target);
        else if(cur_node->val < target)
            tmp = search(cur_node->right, target);
        
        cur_return.insert(cur_return.end(), tmp.begin(), tmp.end());
        
        return cur_return;
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        p_vec = search(root, p->val);
        q_vec = search(root, q->val);
        
        TreeNode* ans = p_vec[0];

        for(int i = 0 ; i < min(p_vec.size(), q_vec.size()) ; i++){
            if(p_vec[i] == q_vec[i])
                ans = p_vec[i];
        }
        
        return ans;
        
    }
};