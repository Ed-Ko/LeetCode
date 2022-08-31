class Solution {
    public int pivotIndex(int[] nums) {
        int[] dp = new int[nums.length];
        Arrays.fill(dp, 0);
        
        dp[0] = nums[0];
        for(int i = 1 ; i < nums.length ; i++)
            dp[i] = dp[i - 1] + nums[i];
        
        for(int i = 0 ; i < nums.length ; i++){
            
            int left_sum = 0;
            int right_sum = 0;
            
            if(i > 0)
                left_sum = dp[i - 1];
            
            if(i < nums.length - 1)
                right_sum = dp[nums.length - 1] - dp[i];
                
            if(left_sum == right_sum)
                return i;
        }
        
        return -1;
    }
}