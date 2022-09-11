class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int, vector<int>> dict;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int cur_int = nums[i];
            int digit_sum = 0;
            while(cur_int > 0){
                digit_sum += cur_int % 10;
                cur_int /= 10;
            }
            dict[digit_sum].push_back(nums[i]);   
        }
        
        int ans = -1;
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            if(it->second.size() >= 2)
                ans = max(it->second[it->second.size() - 1] + it->second[it->second.size() - 2], ans);
        }
        
        return ans;
        
    }
};