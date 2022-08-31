class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_set<int> count_set;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(count_set.count(nums[i]))
                return true;
            count_set.insert(nums[i]);
        }
        
        return false;
        
    }
};