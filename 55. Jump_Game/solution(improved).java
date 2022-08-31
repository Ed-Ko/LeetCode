class Solution {
    public boolean canJump(int[] nums) {
        
        int max_idx = 0;
        
        for(int i = 0 ; i < nums.length ; i++){
            max_idx = Math.max(max_idx, i + nums[i]);
            if(max_idx >= nums.length - 1)
                return true;
            if(max_idx == i)
                return false;
        }
        
        return true;
        
    }
}