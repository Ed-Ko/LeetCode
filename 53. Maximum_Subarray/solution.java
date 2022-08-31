class Solution {
    public int maxSubArray(int[] nums) {
        int ans = -100000;
        int cur_sum = -100000;
        for(int i = 0 ; i < nums.length ; i++){
            cur_sum = Math.max(cur_sum + nums[i], nums[i]);
            ans = Math.max(ans, cur_sum);
        }
        
        return ans;
    }
}