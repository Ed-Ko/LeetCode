class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int max_idx = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            max_idx = max(max_idx, i + nums[i]);
            if(max_idx >= nums.size() - 1)
                return true;
            if(max_idx == i)
                return false;
        }
        
        return true;
        
    }
};