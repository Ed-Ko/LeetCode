class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        int dict[100];
        memset(dict, 0, sizeof(dict));
        
        int ans = -1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int cur_int = nums[i];
            int digit_sum = 0;
            while(cur_int > 0){
                digit_sum += cur_int % 10;
                cur_int /= 10;
            }
            
            if(dict[digit_sum] != 0){
                ans = max(ans, dict[digit_sum] + nums[i]);
                if(dict[digit_sum] < nums[i])
                    dict[digit_sum] = nums[i];
            }
            else
                dict[digit_sum] = nums[i];
            
        }
        
        
        return ans;
        
    }
};