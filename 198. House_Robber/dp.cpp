class Solution {
public:
    
    int rob(vector<int>& nums) {
        
        int dp[101];
        memset(dp, 0, sizeof(dp));
        
        if(nums.size() == 1)
            return nums[0];
        
        int cur_max = INT_MIN;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            if(i == nums.size() - 1 || i == nums.size() - 2)
                dp[i] = nums[i];
            else{
                if(cur_max < dp[i + 2])
                    cur_max = dp[i + 2];
                dp[i] = nums[i] + cur_max;
            }
        }
        
        return dp[0] > dp[1] ? dp[0] : dp[1];
    }
};