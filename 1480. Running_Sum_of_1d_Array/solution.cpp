class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        
        int cur_sum = 0;
        
        vector<int> ans(nums.size(), 0);
        
        for(int i = 0 ; i < nums.size() ; i++){
            cur_sum += nums[i];
            ans[i] = cur_sum;
        }
        
        return ans;
        
        
    }
};