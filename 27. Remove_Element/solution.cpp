class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        vector<int> ans;
        int val_count = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] != val)
                ans.push_back(nums[i]);
            else
                val_count++;
        }
        
        nums = ans;
        return ans.size();
    } 
};