class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        map<int,int> dict;
        int ans;
        
        for(int i = 0 ; i < nums.size() ; i++)
            dict[nums[i]]++;
        
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            if(it->second == 1){
                ans = it->first;
                break;
            }
        }
        return ans;
    }
};