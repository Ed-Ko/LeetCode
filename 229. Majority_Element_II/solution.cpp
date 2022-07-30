class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int bound = nums.size() / 3;
        vector<int> ans;
        
        map<int,int> dict;
        
        for(int i = 0 ; i < nums.size() ; i++)
            dict[nums[i]]++;
        
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            if(it->second > bound)
                ans.push_back(it->first);
        }
        
        return ans;
        
    }
};