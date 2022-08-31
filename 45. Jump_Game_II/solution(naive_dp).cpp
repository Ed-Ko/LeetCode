class Solution {
public:
    int jump(vector<int>& nums) {
        
        vector<int> dp(nums.size(), INT_MAX - 1);
        
        dp[0] = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i + 1 ; j <= i + nums[i] && j < nums.size() ; j++){
                if(dp[j] > dp[i] + 1)
                    dp[j] = dp[i] + 1;
            }
        }
        
        return dp[nums.size() - 1];
        
    }
};