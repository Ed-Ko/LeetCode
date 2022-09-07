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
    
    void BFS(TreeNode* root){
        
        queue<TreeNode*> q;
        q.push(root);
        
        int counter = 1;
        while(!q.empty()){
            
            int next_counter = 0;
            vector<int> cur_vec;

            for(int i = 0 ; i < counter ; i++){
                TreeNode* cur_node = q.front();
                q.pop();
                cur_vec.push_back(cur_node->val);
                if(cur_node->left != nullptr){
                    q.push(cur_node->left);
                    next_counter++;
                }
                if(cur_node->right != nullptr){
                    q.push(cur_node->right);
                    next_counter++;
                }
            }
            
            ans.push_back(cur_vec);
            counter = next_counter;
        }

    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != nullptr)
            BFS(root);
        
        return ans;
    }
};