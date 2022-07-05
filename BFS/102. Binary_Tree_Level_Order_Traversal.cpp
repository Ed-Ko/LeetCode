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
    queue<TreeNode*> node_queue;
    
    int level = 0;
    
    void BFS(){
        
        while(!node_queue.empty()){
            
            vector<TreeNode*> level_vec;
            vector<int> cur_vec;
            
            while(!node_queue.empty()){
                level_vec.push_back(node_queue.front());
                node_queue.pop();
            }
            

            for(int i = 0 ; i < level_vec.size() ; i++){
                TreeNode* cur_node = level_vec[i];
                cur_vec.push_back(cur_node->val);
                if(cur_node->left != nullptr)
                    node_queue.push(cur_node->left);
                if(cur_node->right != nullptr)
                    node_queue.push(cur_node->right);
            }
            
            /*
            for(int i = 0 ; i < cur_vec.size() ; i++)
                cout << cur_vec[i] << " ";
            cout << endl;
            */
            
            ans.push_back(cur_vec);
            
        }

    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root != nullptr)
            node_queue.push(root);
        BFS();
        return ans;
    }
};