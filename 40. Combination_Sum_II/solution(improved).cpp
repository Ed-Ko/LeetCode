class Solution {
public:
    
    vector<vector<int>> ans;
    
    void recur(vector<int>& cur_vec, int target, vector<int>& candidates, int cur_idx){
        
        if(target == 0){
            ans.push_back(cur_vec);
            return;
        }
        
        for(int i = cur_idx ; i < candidates.size() ; i++){
            
            if(i > cur_idx && candidates[i] == candidates[i - 1])
                continue;
            
            if(target - candidates[i] < 0)
                break;
            
            cur_vec.push_back(candidates[i]);
            
            recur(cur_vec, target - candidates[i], candidates, i + 1);
            
            cur_vec.pop_back();
            
        }
        
        return;
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        vector<int> cur_vec;
        sort(candidates.begin(), candidates.end());
        
        recur(cur_vec, target, candidates, 0);
        
        return ans;
        
    }
};