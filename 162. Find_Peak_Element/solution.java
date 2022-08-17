class Solution {
    public int findPeakElement(int[] nums) {
        
        int left = 0;
        int right = nums.length - 1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
            
            boolean cond1 = (mid - 1 >= 0 && nums[mid - 1] < nums[mid] && mid + 1 < nums.length && nums[mid + 1] < nums[mid]);
            boolean cond2 = (mid - 1 < 0 && mid + 1 < nums.length && nums[mid + 1] < nums[mid]);
            boolean cond3 = (mid + 1 >= nums.length && mid - 1 >= 0 && nums[mid - 1] < nums[mid]);
            boolean cond4 = (nums.length == 1);
            
            if(cond1 || cond2 || cond3 || cond4)
                return mid;
            else if(mid - 1 >= 0 && nums[mid] < nums[mid - 1])
                right = mid - 1;
            else
                left = mid + 1;
            
        }
        
        return -1;
        
    }
}