class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        
        int left = 0;
        int right = 0;
        
        int ans = Integer.MAX_VALUE;
        
        int cur_sum = 0;
        
        while(right < nums.length){
            
            cur_sum += nums[right];
            
            while(cur_sum >= target){
                ans = Math.min(ans, right - left + 1);
                cur_sum -= nums[left];
                left++;
            }
            
            right++;
            
        }
        
        if(ans != Integer.MAX_VALUE)
            return ans;
        return 0;
        
    }
}