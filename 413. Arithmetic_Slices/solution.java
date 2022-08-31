class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        
        if(nums.length < 3)
            return 0;
        
        ArrayList<Integer> sep = new ArrayList<Integer>();
        sep.add(0);
        
        int ans = 0;
        
        int hist_dif = nums[1] - nums[0];
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i]  - nums[i - 1] != hist_dif){
                sep.add(i - 1);
                hist_dif = nums[i] - nums[i - 1];
            }
        }
        
        sep.add(nums.length - 1);
        
        for(int i = 0 ; i < sep.size() ; i++){
            if(i + 1 < sep.size() && sep.get(i + 1) - sep.get(i) >= 2){
                for(int j = sep.get(i + 1) - sep.get(i) ; j >= 2 ; j--){
                    ans += (sep.get(i + 1) - sep.get(i) + 1 - j);
                }
            }
        }
        
        return ans;
        
        
        
    }
}