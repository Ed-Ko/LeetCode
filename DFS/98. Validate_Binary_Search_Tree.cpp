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
    vector<int> ans;
    void DFS(TreeNode* cur_node){
       if(cur_node != nullptr){
           if(cur_node->left != nullptr)
               DFS(cur_node->left);
           ans.push_back(cur_node->val);
           if(cur_node->right != nullptr)
               DFS(cur_node->right);
       }
    }
    bool isValidBST(TreeNode* root) {
        DFS(root);
        bool check = true;
        for(int i = 1 ; i < ans.size() ; i++){
            if(!(ans[i-1] < ans[i])){
                check = false;
                break;
            }
        }
        return check;
    }
};