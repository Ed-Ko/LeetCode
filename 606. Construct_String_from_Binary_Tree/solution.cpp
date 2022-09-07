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
    
    string recur(TreeNode* cur_node){
        
        if(cur_node == nullptr)
            return "";
        
        string cur_str = to_string(cur_node->val);
    
        if(cur_node->left != nullptr || cur_node->right != nullptr){
            
            string left = "()";
            string right = "()";
            
            if(cur_node->left != nullptr)
                left.insert(1, recur(cur_node->left));
            
            cur_str.append(left);
            
            if(cur_node->right != nullptr)
                right.insert(1, recur(cur_node->right));
            
            if(cur_node->right != nullptr)
                cur_str.append(right);
        }
        
        return cur_str;
    }
    
    string tree2str(TreeNode* root) {
        
        return recur(root);
        
    }
};