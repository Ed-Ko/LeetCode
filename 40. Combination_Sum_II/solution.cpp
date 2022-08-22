class Solution {
public
    
    vectorvectorint ans;
    mapint,int dict;
    
    void recur(vectorint& cur_vec, int target, vectorint& candidates, int cur_idx){
        
        if(cur_idx  0){
            if(target == 0)
                ans.push_back(cur_vec);
            
            return;
        }
        
        recur(cur_vec, target, candidates, cur_idx - 1);
        
        
        if(target - candidates[cur_idx] = 0 && dict[candidates[cur_idx]]  0){
            cur_vec.push_back(candidates[cur_idx]);
            dict[candidates[cur_idx]]--;
            recur(cur_vec, target - candidates[cur_idx], candidates, cur_idx);
            dict[candidates[cur_idx]]++;
            cur_vec.pop_back();
        }
        
        return;
    }
    
    vectorvectorint combinationSum2(vectorint& candidates, int target) {
        
        
        vectorint candidates2;
        
        for(int i = 0 ; i  candidates.size() ; i++){
            
            if(dict[candidates[i]] == 0)
                candidates2.push_back(candidates[i]);
            
            dict[candidates[i]]++;
        }
        
        vectorint cur_vec;
        sort(candidates2.begin(), candidates2.end());
        
        recur(cur_vec, target, candidates2, candidates2.size() - 1);
        
        return ans;
        
    }
};