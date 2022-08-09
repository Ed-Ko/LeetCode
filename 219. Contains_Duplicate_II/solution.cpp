class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
        int limit;
        
        map<int,int> dict;
        
        if(nums.size() - 1 < k)
            limit = nums.size() - 1;
        else
            limit = k;
        
        bool ans = false;
        for(int i = 0 ; i <= limit ; i++){
            dict[nums[i]]++;
            if(dict[nums[i]] > 1)
                return true;
        }

        for(int i = 0 ; i + limit + 1 < nums.size() ; i++){
            dict[nums[i]]--;
            //cout <<  << dict[nums[i + limit + 1]] << endl;
            if(dict[nums[i + limit + 1]] == 1)
                return true;
            dict[nums[i + limit + 1]]++;
        }
        
        return false;
    }
};