class Solution {
public:
    
    int BS(vector<int>& nums, int target, int status){
        
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
        
            if(nums[mid] < target)
                left = mid + 1;
            else if(nums[mid] > target)
                right = mid - 1;
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
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        vector<int> ans(2, 0);
        
        if(nums.size() == 0 || right < left){
            ans[0] = -1;
            ans[1] = -1;
            return ans;
        }
             
        ans[0] = BS(nums, target, 0);
        ans[1] = BS(nums, target, 1);
        
        
        return ans;
    }
};