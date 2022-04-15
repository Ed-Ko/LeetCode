class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_arr[nums.size()];
        max_arr[0] = nums[0];


        int ans = max_arr[0];

        int left=0;
        int right=0;

        for(int i = 1 ; i < nums.size() ; i++){

            max_arr[i] = max(nums[i] + max_arr[i-1], nums[i]);

            if(ans < max_arr[i])
                ans = max_arr[i];
        }
        
        return ans;
    }
};