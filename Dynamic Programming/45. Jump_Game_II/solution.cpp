class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;

        int confirm[nums.size()];
        confirm[nums.size()-1] = 0;

        if(nums.size() == 1)
            return 0;
        
        for(int i = nums.size() - 2 ; i >= 0 ; i--){

            confirm[i] = -1;

            if(i + nums[i] >= nums.size() - 1)
                confirm[i] = 1;
            else{
                int min_choice = INT_MAX;
                for(int j = 1 ; j <= nums[i] && (i+j < nums.size()) ; j++){
                    if(confirm[i+j] > 0 && confirm[i+j] < min_choice)
                        min_choice = confirm[i+j];
                }
                if(min_choice != INT_MAX)
                    confirm[i] = min_choice + 1; 
            }
        }
        
        return confirm[0];
        
    }
};