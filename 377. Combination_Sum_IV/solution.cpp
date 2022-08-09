class Solution {
public:
    
    vector<int> dp;
    
    int recur(vector<int>& nums, int target){
        
        
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];

        
        int cur_count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(target - nums[i] >= 0){
                cur_count += recur(nums, target - nums[i]);
            }
        }
        
        dp[target] = cur_count;
        return cur_count;
        
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        dp.resize(target + 1, -1);
        
        recur(nums, target);
        
        return dp[target];
    }
};