class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> ans;
        map<int,int> dict;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(dict.find(pow(nums[i],2)) == dict.end())
                dict[pow(nums[i],2)] = 1;
            else
                dict[pow(nums[i],2)]++;
        }
        
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            for(int i = 0 ; i < it->second ; i++)
                ans.push_back(it->first);
        }
        
        return ans;
    }
};