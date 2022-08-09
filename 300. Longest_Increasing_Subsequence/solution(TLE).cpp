class Solution {
public:
    
    int recur(vector<int>& nums, int cur_idx){
        
        int cur_len = 0;
        
        if(cur_idx == nums.size() - 1)
            return 1;
        
        for(int i = cur_idx + 1 ; i < nums.size() ; i++){
            if(nums[cur_idx] < nums[i]){
                int cur_return = recur(nums, i);
                if(cur_return > cur_len)
                    cur_len = cur_return;
            }
        }
        
        
        return cur_len + 1;
    }
    
    
    int lengthOfLIS(vector<int>& nums) {
        
        int final_return = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int cur_return = recur(nums, i);
            if(final_return < cur_return)
                final_return = cur_return;
        }
        
        
        return final_return;
        
    }
};