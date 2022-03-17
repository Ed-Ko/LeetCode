class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = 100000;
        map<int,int> dict;
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){ 
            int val = target - nums[i];
            for(int j = 0 ; j < nums.size() && j < i ; j++){

                if((dict.find(val - nums[j]) != dict.end()) && (dict[val - nums[j]] != j)){
                    ans = target;
                    break;
                }


                int idx = 0;
                while(idx < j){
                    if(abs(nums[idx] + nums[j] + nums[i] - target) < abs(ans - target))
                        ans = nums[idx] + nums[j] + nums[i];
                    idx++;
                }

            }
            if(ans == target)
                break;
            dict[nums[i]] = i;
        }
        
        return ans;
    }
};