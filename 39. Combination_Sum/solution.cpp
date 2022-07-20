class Solution {
public:
    
    vector<vector<int>> ans;
    
    void recur(vector<int>& candidates, int target, vector<int> cur_vec, int cur_idx){
        
        if(target == 0){
            ans.push_back(cur_vec);
            return;
        }
            
        while(cur_idx < candidates.size() && target - candidates[cur_idx] >= 0){
            
            cur_vec.push_back(candidates[cur_idx]);
            
            recur(candidates, target - candidates[cur_idx], cur_vec, cur_idx);
            cur_idx++;
            
            cur_vec.pop_back();
        }
        
        
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());
        
        vector<int> start;
        recur(candidates, target, start, 0);
        return ans;
        
    }
};