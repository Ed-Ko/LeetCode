class Solution {
public:
    
    int recur(vector<int>& nums, vector<int>& dp, int pre_idx, int idx, int split_num){
        
        if(split_num == 1)
            return dp[nums.size() - 1] - dp[pre_idx];
        
        if(pre_idx == 0 && idx == 0){
            int last_sum = dp[0];
            int last_remain = dp[nums.size() - 1] - dp[0];
            for(int i = 0 ; i <= nums.size() - split_num ; i++){
                int cur_sum = dp[i];
                int cur_remain = recur(nums, dp, i, i + 1, split_num - 1);
                
                int last_big = max(last_sum, last_remain);
                int cur_big = max(cur_sum, cur_remain);
                
                if(cur_big < last_big){
                    last_sum = cur_sum;
                    last_remain = cur_remain;
                }
                
            }
            //cout << last_sum << " " << last_remain << endl;
            return max(last_sum, last_remain);
        }
        else{
            int last_sum = dp[idx] - dp[pre_idx];
            int last_remain = dp[nums.size() - 1] - dp[idx];
            for(int i = idx ; i <= nums.size() - split_num ; i++){
                int cur_sum = dp[i] - dp[pre_idx];
                int cur_remain = recur(nums, dp, i, i + 1, split_num - 1);
                
                int last_big = max(last_sum, last_remain);
                int cur_big = max(cur_sum, cur_remain);
                
                if(cur_big < last_big){
                    last_sum = cur_sum;
                    last_remain = cur_remain;
                }
            }    
            //cout << last_sum << " == " << last_remain << endl;            
            return max(last_sum, last_remain);
        }
        
        
        return -1;
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        vector<int> dp;
        
        int cur_sum = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            cur_sum += nums[i];
            dp.push_back(cur_sum);
        }

        if(m == 1)
            return dp[nums.size() - 1];
            
        
        int ans = recur(nums, dp, 0, 0, m);
        
        return ans;
        
    }
};