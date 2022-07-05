class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> ans;
        
        int fin_idx = (nums.size() - (k % nums.size())) % nums.size();
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(fin_idx + i < nums.size() - 1)
                ans.push_back(nums[fin_idx + i]);
            else
                ans.push_back(nums[(fin_idx + i) % nums.size()]);
        }
        
        nums = ans;
        
        return;
    }
};