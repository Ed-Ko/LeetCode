class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

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

                if((nums[left] + nums[right] + nums[i]) == 0){
                    vector<int> buf;
                    buf.insert(buf.end(),{nums[i], nums[left], nums[right]});
                    ///if(find(ans.begin(), ans.end(), buf) == ans.end())
                    ans.push_back(buf);
                    right--;
                }
                else if((nums[left] + nums[right] + nums[i]) < 0)
                    left++;
                else
                    right--;

            }
        }
        
        return ans;
    }
};