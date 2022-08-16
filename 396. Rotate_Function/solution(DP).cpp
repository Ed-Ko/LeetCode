class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        long long sum2 = 0;
        long long sum1 = 0;
        vector<long long> dp1(nums.size() + 1, 0);
        vector<long long> dp2(nums.size() + 1, 0);
        
        for(int i = 0 ; i < nums.size() ; i++)
            sum2 += (i * nums[i]);
        
        dp2[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            dp1[i] = dp1[i - 1] + nums[i];
            dp2[i] = nums[nums.size() - i] + dp2[i - 1];
        }
            
        long long cur_sum = sum1 + sum2;
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            sum2 += dp1[nums.size() - i];
            sum2 -= (nums.size() * nums[nums.size() - i]);
            
            sum1 += dp2[i - 1];
            
            if(sum1 + sum2 > cur_sum)
                cur_sum = sum1 + sum2;
        }
        
        return cur_sum;
        
    }
};