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
        
        queue<pair<int,int>> q;
        queue<TreeNode*> node_q;
        q.push(make_pair(0, 0));
        node_q.push(root);
        
        int counter = 1;
        while(!q.empty()){
            int next_counter = 0;
            map<int, vector<int>> cur_map;
            for(int i = 0 ; i < counter ; i++){
                pair<int,int> cur_pos = q.front();
                TreeNode* cur_node = node_q.front();
                q.pop();
                node_q.pop();
                
                cur_map[cur_pos.second].push_back(cur_node->val);
                if(cur_node->left != nullptr){
                    q.push(make_pair(cur_pos.first + 1, cur_pos.second - 1));
                    node_q.push(cur_node->left);
                    next_counter++;
                }
                if(cur_node->right != nullptr){
                    q.push(make_pair(cur_pos.first + 1, cur_pos.second + 1));
                    node_q.push(cur_node->right);
                    next_counter++;
                }
                
            }
            
            for(auto it = cur_map.begin() ; it != cur_map.end() ; it++){
                sort(it->second.begin(), it->second.end());
                ans[it->first + 1000].insert(ans[it->first + 1000].end(), it->second.begin(), it->second.end());
            }
            
            counter = next_counter;
            
        }
        
        
        return;
        
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        ans.resize(2000, vector<int>());
        
        traverse(root);
        
        for(int i = 0 ; i < ans.size() ; ){
            if(ans[i].size() == 0)
                ans.erase(ans.begin() + i);
            else
                i++;
        }
        
        return ans;
    }