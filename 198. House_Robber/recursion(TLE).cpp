class Solution {
public:
    
    int recur(vector<int>& nums, int cur_idx){
        
        if(cur_idx > nums.size() - 1)
            return 0;
        
        if(cur_idx == nums.size() - 1 || cur_idx == nums.size() - 2)
            return nums[cur_idx];
        
        
        int max_return = 0;
        
        for(int i = cur_idx + 2 ; i < nums.size() ; i++){
            int cur_return = recur(nums, i);
            if(cur_return > max_return)
                max_return = cur_return;
        }
        
        return max_return + nums[cur_idx];
    }
    
    
    int rob(vector<int>& nums) {
        
        int odd_sum = recur(nums, 1);
        int even_sum = recur(nums, 0);
        
        return odd_sum > even_sum ? odd_sum : even_sum;
    }
};