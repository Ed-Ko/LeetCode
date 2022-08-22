class Solution {
public:
    
    map<int,int> dict;
    vector<vector<int>> ans;
    
    void recur(vector<int>& nums, vector<int> cur_vec, int depth, int cur_val){
        
        cur_vec.push_back(cur_val);
        
        if(depth == 0){
            ans.push_back(cur_vec);
            return;
        }
        
        for(auto it = dict.find(cur_val) ; it != dict.end() ; it++){
            
            if(it->second > 0){
                it->second--;
                recur(nums, cur_vec, depth - 1, it->first);
                it->second++;
            }
            
            
        }
        
        return;
        
    }
    
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        for(int i = 0 ; i < nums.size() ; i++)
            dict[nums[i]]++;
        
        vector<int> start;
        ans.push_back(start);
        for(int i = 1 ; i <= nums.size() ; i++){
            for(auto it = dict.begin() ; it != dict.end() ; it++){
                it->second--;
                recur(nums, start, i - 1, it->first);
                it->second++;
            }
                    
        }
        
        return ans;
        
    }
};