class Solution {
public:
    
    vector<int> recur(vector<int>& nums, int idx, vector<vector<int>>& dp){
        
        if(idx > nums.size() - 1)
            return {};
        
        if(dp[idx].size() != 0)
            return dp[idx];
        
        vector<int> cur_ans;
        
        for(int i = idx + 1 ; i < nums.size() ; i++){
            
            if(nums[i] % nums[idx] == 0){
                vector<int> cur_return = recur(nums, i, dp);
                if(cur_return.size() > cur_ans.size())
                    cur_ans = cur_return;
            }
            
        }
        
        cur_ans.insert(cur_ans.begin(), nums[idx]);
        
        dp[idx] = cur_ans;
        return cur_ans;
        
    }
    
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        vector<int> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            vector<vector<int>> dp(nums.size(), vector<int>());
            vector<int> cur_return = recur(nums, i, dp);
            if(cur_return.size() > ans.size())
                ans = cur_return;
        }
        
        
        
        return ans;
        
    }
};