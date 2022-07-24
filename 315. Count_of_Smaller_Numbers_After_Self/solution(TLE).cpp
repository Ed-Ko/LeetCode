class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        
        map<int,vector<int>> dict;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(dict.find(nums[i]) != dict.end())
                dict[nums[i]].push_back(i);
            else{
                vector<int> tmp;
                dict[nums[i]].push_back(i);
            }
        }
        
        vector<int> ans;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int cur_num = nums[i];
            int cur_sum = 0;
            for(auto it = dict.begin() ; it != dict.end() && it->first != cur_num ; it++){
                for(int j = 0 ; j < it->second.size() ; j++){
                    if(it->second[j] > i)
                        cur_sum++;
                }
            }
            ans.push_back(cur_sum);
        }
        
        return ans;
    }
};