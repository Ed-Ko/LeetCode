class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        if(left == right)
            return nums[left];
        
        while(left <= right){
            
            mid = left + (right - left) / 2;
            
            
            if(left == right - 1){
                if(nums[left] < nums[right])
                    return nums[left];
                else
                    return nums[right];
            }
            
            if(nums[left] < nums[mid] && nums[mid] < nums[right])
                return nums[left];
            
            
            //if(nums[mid] < nums[left] || nums[right] < nums[mid])
            if(nums[left] <= nums[mid])
                left = mid;
            else
                right = mid;
        }
        
        return nums[mid];
        
    }
};