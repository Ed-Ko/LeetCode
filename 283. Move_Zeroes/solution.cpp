class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int zero_num = 0;
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == 0)
                zero_num++;
            else
                ans.push_back(nums[i]);
        }
        for(int i = 0 ; i < zero_num ; i++)
            ans.push_back(0);
        
        nums = ans;
        return;
    }
};