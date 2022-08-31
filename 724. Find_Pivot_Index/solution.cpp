class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int dp[nums.size()];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++)
            dp[i] = dp[i - 1] + nums[i];
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int left_sum = 0;
            int right_sum = 0;
            
            if(i > 0)
                left_sum = dp[i - 1];
            
            if(i < nums.size() - 1)
                right_sum = dp[nums.size() - 1] - dp[i];
                
            if(left_sum == right_sum)
                return i;
        }
        
        return -1;
    }
};