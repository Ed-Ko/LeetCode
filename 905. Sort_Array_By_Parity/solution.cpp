class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        vector<int> ans;
        vector<int> tmp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] % 2 == 0)
                ans.push_back(nums[i]);
            else
                tmp.push_back(nums[i]);
        }
        
        for(int i = 0 ; i < tmp.size() ; i++)
            ans.push_back(tmp[i]);
        
        
        return ans;
    }
};