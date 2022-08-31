class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        
        if(nums.length < 3)
            return 0;
                
        int ans = 0;
        
        int hist_dif = nums[1] - nums[0];
        int count = 1;
        for(int i = 2 ; i < nums.length ; i++){
            if(nums[i]  - nums[i - 1] != hist_dif){
                hist_dif = nums[i] - nums[i - 1];
                count = 1;
            }
            else{
                count++;
                if(count >= 2)
                    ans += (count - 1);
            }
        }
        
        
        return ans;

    }
}