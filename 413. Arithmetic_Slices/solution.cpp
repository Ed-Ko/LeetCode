class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        if(nums.size() < 3)
            return 0;
        
        vector<int> sep;
        sep.push_back(0);
        
        int ans = 0;
        
        int hist_dif = nums[1] - nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i]  - nums[i - 1] != hist_dif){
                sep.push_back(i - 1);
                hist_dif = nums[i] - nums[i - 1];
            }
                
        }
        
        sep.push_back(nums.size() - 1);
        
        for(int i = 0 ; i < sep.size() ; i++){
            if(i + 1 < sep.size() && sep[i + 1] - sep[i] >= 2){
                for(int j = sep[i + 1] - sep[i] ; j >= 2 ; j--){
                    ans += (sep[i + 1] - sep[i] + 1 - j);
                }
            }
        }
        
        return ans;
        
    }
};