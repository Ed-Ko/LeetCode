class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = nums[0];
        
        int max_sum = nums[0];
        int min_sum = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            if(nums[i] < 0)
                swap(max_sum, min_sum);
            
            max_sum = max(nums[i], max_sum * nums[i]);
            min_sum = min(nums[i], min_sum * nums[i]);
            
            ans = max(ans, max_sum);
            
        }
        
        return ans;
        
    }
};