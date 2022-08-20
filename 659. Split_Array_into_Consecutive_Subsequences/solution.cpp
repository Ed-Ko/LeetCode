class Solution {
public:
    bool isPossible(vector<int>& nums) {
        
        map<int,int> dict;
        map<int,int> check;
        
        for(int i = 0 ; i < nums.size() ; i++)
            dict[nums[i]]++;
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(dict[nums[i]] == 0)
                continue;
            
            if(check[nums[i]] > 0){
                check[nums[i]]--;
                dict[nums[i]]--;
                check[nums[i] + 1]++;
            }
            else if(dict[nums[i]] > 0 && dict[nums[i] + 1] > 0 && dict[nums[i] + 2] > 0){
                dict[nums[i]]--;
                dict[nums[i] + 1]--;
                dict[nums[i] + 2]--;
                
                check[nums[i] + 3]++;
            }
            else
                return false;
            
        }
        
        return true;
        
    }
};