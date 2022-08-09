class Solution {
public:
    
    int recur(vector<int>& nums, int cur_idx, vector<int>& dp){
        
        int cur_len = 0;
        
        if(dp[cur_idx] != -1)
            return dp[cur_idx];
        
        
        for(int i = cur_idx + 1 ; i < nums.size() ; i++){
            if(nums[cur_idx] < nums[i]){
                int cur_return = recur(nums, i, dp);
                if(cur_return > cur_len)
                    cur_len = cur_return;
            }
        }
        
        dp[cur_idx] = cur_len + 1;
        
        return cur_len + 1;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int final_return = 0;
        vector<int> dp(nums.size(), -1);
        
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            int cur_return = recur(nums, i, dp);
            if(final_return < cur_return)
                final_return = cur_return;
        }
        
        
        return final_return;
        
    }
};