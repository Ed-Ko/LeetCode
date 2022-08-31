class Solution {
    public int[] runningSum(int[] nums) {
        
        int cur_sum = 0;
        
        int[] ans = new int[nums.length];
        
        for(int i = 0 ; i < nums.length ; i++){
            cur_sum += nums[i];
            ans[i] = cur_sum;
        }
        
        return ans;
        
    }
}