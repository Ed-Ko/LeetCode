class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int change = 1;
        
        while(left < right - 1){
            int cur_idx = (left + right) / 2;
            if(nums[cur_idx] == target)
                return cur_idx;
            else{
                if(target > nums[cur_idx])
                    left = cur_idx;
                
                else
                    right = cur_idx;
            }
        }
        
        if(nums[left] == target)
            return left;
        else if(nums[right] == target)
            return right;
        else if(nums[left] > target)
            return 0;
        else if(nums[right] < target)
            return nums.size();
        return left + 1;
        
    }
};