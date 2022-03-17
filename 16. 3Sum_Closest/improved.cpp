class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 100000;

        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            
            if((i - 1 >= 0) && (nums[i] == nums[i-1]))
                continue;

            int left = i + 1;
            int right = (nums.size() - 1);
            while(left < right){

                if((right + 1 < nums.size()) && (nums[right] == nums[right + 1])){
                    right--;
                    continue;
                }

                if(abs(nums[left] + nums[right] + nums[i] - target) < abs(ans - target))
                    ans = nums[left] + nums[right] + nums[i];
                
                if((nums[left] + nums[right] + nums[i] - target) < 0)
                    left++;
                else if((nums[left] + nums[right] + nums[i] - target) > 0)
                    right--;
                else{
                    ans = target;
                    break;
                }
            }
            
            if(ans == target)
                break;
        }
        
        return ans;
    }
};