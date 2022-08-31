class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = -100000;
        int cur_sum = -100000;
        for(int i = 0 ; i < nums.size() ; i++){
            cur_sum = max(cur_sum + nums[i], nums[i]);
            ans = max(ans, cur_sum);
        }
        
        return ans;
    }
};