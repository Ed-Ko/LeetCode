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
    
    void traverse(TreeNode* root){
        
        map<int, map<int, multiset<int>>> dict;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            TreeNode* cur_node = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            dict[row][col].insert(cur_node->val);
            
            if(cur_node->left != nullptr)
                q.push({cur_node->left, {row - 1, col + 1}});
            if(cur_node->right != nullptr)
                q.push({cur_node->right, {row + 1, col + 1}});
            
        }
        
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            vector<int> tmp;
            for(auto it2 = it->second.begin() ; it2 != it->second.end() ; it2++)
                tmp.insert(tmp.end(), it2->second.begin(), it2->second.end());
            ans.push_back(tmp);
        }
           
        return;
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
                
        traverse(root);
        
        
        return ans;
    }
};