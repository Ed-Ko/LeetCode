class Solution {
    public int search(int[] nums, int target) {
        
        int ans = -1;
        
        int left = 0;
        int right = nums.length - 1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
            //System.out.println(mid);
            if(nums[mid] == target){
                System.out.println(nums[mid]);
                ans = mid;
                break;
            }
            else if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else{
                if(nums[mid] <= target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            
        }
        
        
        return ans;
        
    }
}