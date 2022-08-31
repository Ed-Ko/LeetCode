class Solution {
    public boolean containsDuplicate(int[] nums) {
        
        Set<Integer> count_set = new HashSet<Integer>();
        
        for(int i = 0 ; i < nums.length ; i++){
            if(count_set.contains(nums[i]))
                return true;
            count_set.add(nums[i]);
        }
        
        return false;
        
        
    }
}