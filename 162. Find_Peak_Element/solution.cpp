class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        if(nums.size() == 1)
            return 0;
        if(nums.size() == 2){
            if(nums[0] > nums[1])
                return 0;
            else
                return 1;
        }
            
            
        while(left < right){
            
            int mid = (left + right) / 2;
                        
            if(mid == 0){
                if(nums[mid] > nums[mid + 1])
                    return 0;
            }
            if(mid == nums.size() - 1){
                if(nums[mid] > nums[mid - 1])
                    return nums.size() - 1;
            }
            if(nums[mid - 1] < nums[mid] && nums[mid] > nums[mid + 1])
                return mid;
            
            if(nums[mid] <= nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        
        return left;
    }
};