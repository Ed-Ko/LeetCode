class Solution {
public:
    
    vector<vector<int>> ans;
    set<vector<int>> s;
    
    void swapper(vector<int>& nums, int idx){
        
        if(idx == nums.size()){
            s.insert(nums);
            return;
        }
        
        for(int i = idx ; i < nums.size() ; i++){
            swap(nums[idx], nums[i]);
            swapper(nums, idx + 1);
            swap(nums[idx], nums[i]);
        }
        
        return;
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
       
        swapper(nums, 0);
        
        for(auto it : s)
            ans.push_back(it);
        
        return ans;
    }
};