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
    
    bool preorder(TreeNode* cur_node, TreeNode* sub){
        
        if(cur_node != nullptr && sub != nullptr && cur_node->val == sub->val){
            
            bool left_ans = true;
            bool right_ans = true;
            
            if(cur_node->left != nullptr && sub->left != nullptr)
                left_ans = preorder(cur_node->left, sub->left);
            else if(cur_node->left == nullptr && sub->left == nullptr)
                left_ans = true;
            else
                left_ans = false;
            
            if(cur_node->right != nullptr && sub->right != nullptr)
                right_ans = preorder(cur_node->right, sub->right);
            else if(cur_node->right == nullptr && sub->right == nullptr)
                right_ans = true;
            else
                right_ans = false;
                
            return left_ans && right_ans;
        }
        else if(cur_node == nullptr && sub == nullptr)
            return true;
            
        
        return false;
    }
        
    bool inorder(TreeNode* cur_node, TreeNode* sub){
        
        if(cur_node == nullptr && sub == nullptr)
            return true;
        
        else if(cur_node != nullptr && sub != nullptr){
            
            bool left_ans = true;
            bool right_ans = true;
            
            if(cur_node->left != nullptr && sub->left != nullptr)
                left_ans = inorder(cur_node->left, sub->left);
            else if(cur_node->left == nullptr && sub->left == nullptr)
                left_ans = true;
            else
                left_ans = false;
            
            if(cur_node->val != sub->val)
                return false;
            
            
            if(cur_node->right != nullptr && sub->right != nullptr)
                right_ans = inorder(cur_node->right, sub->right);
            else if(cur_node->right == nullptr && sub->right == nullptr)
                right_ans = true;
            else
                right_ans = false;
            
            return left_ans && right_ans;
            
        }
        
        return false;            

    }
    
    bool search(TreeNode* cur_node, TreeNode* subRoot){
        
        if(cur_node->val == subRoot->val){
            if(preorder(cur_node, subRoot) && inorder(cur_node, subRoot))
                return true;
        }
        
        bool left_ans = false;
        bool right_ans = false;
        
        if(cur_node->left != nullptr)
            left_ans = search(cur_node->left, subRoot);
        if(cur_node->right != nullptr)
            right_ans = search(cur_node->right, subRoot);
        
        
        return left_ans || right_ans;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
        return search(root, subRoot);
        
    }
};