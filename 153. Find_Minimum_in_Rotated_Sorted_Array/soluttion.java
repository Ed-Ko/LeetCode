class Solution {
    public int findMin(int[] nums) {
        
        int left = 0;
        int right = nums.length - 1;
        
        int ans = Integer.MAX_VALUE;
        int mid;
        
        while(left <= right){
            
            mid = (left + right) / 2;
            
            if(nums[mid] < ans)
                ans = nums[mid];
            
            
            if(nums[left] <= nums[mid]){
                if(nums[left] < nums[right])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
                right = mid - 1;
        }
        
        return ans;
        
    }
}