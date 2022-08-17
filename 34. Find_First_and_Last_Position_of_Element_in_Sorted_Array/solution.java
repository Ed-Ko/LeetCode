class Solution {
    
    public int BS(int[] nums, int target, int status){
        
        int ans = -1;
        int left = 0;
        int right = nums.length - 1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
            
            if(target < nums[mid])
                right = mid - 1;
            else if(target > nums[mid])
                left = mid + 1;
            else{
                
                ans = mid;
                
                if(status == 0)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            
            
        }
        
        return ans;
        
    }
    
    
    
    public int[] searchRange(int[] nums, int target) {
        
        int[] ans = {-1,-1};
        
        ans[0] = BS(nums, target, 0);
        if(ans[0] == -1)
            return ans;
        ans[1] = BS(nums, target, 1);
        
        return ans;
        
    }
}