class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        
        List<List<Integer>> ans = new ArrayList<List<Integer>>();
        
        Arrays.sort(nums);
        
        for(int i = 0 ; i < nums.length - 2 ; i++){
            
            if(i - 1 >= 0 && nums[i] == nums[i - 1])
                continue;
            
            int cur_dif = -1 * nums[i];
            
            int left = i + 1;
            int right = nums.length - 1;
            
            while(left < right){
                
                if(nums[left] + nums[right] == cur_dif){
                    List<Integer> tmp = new ArrayList<Integer>();
                    tmp.add(nums[i]);
                    tmp.add(nums[left]);
                    tmp.add(nums[right]);
                    ans.add(tmp);
                    
                    right--;
                    
                    while(left < right && nums[right] == nums[right + 1])
                        right--;
                    
                }
                else if(nums[left] + nums[right] < cur_dif)
                    left++;
                else
                    right--;
                
            }
            
            
            
        }
        
        return ans;
        
    }
}