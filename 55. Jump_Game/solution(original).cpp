class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        bool ans = true;

        bool confirm[nums.size()];
        confirm[nums.size() - 1] = true;
        
        if(nums.size() == 1)
            return ans;
        

        for(int i = nums.size() - 2 ; i >= 0 ; i--){

            confirm[i] = false;

            if(i + nums[i] >= nums.size() - 1)
                confirm[i] = true;

            for(int j = 1 ; j <= nums[i] && (i+j < nums.size()-1) ; j++){
                if(confirm[i+j] == true){
                    confirm[i] = true;
                    break;
                }
            }
        }
        
        return confirm[0];
    }
};