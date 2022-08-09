class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        map<int,int> dict;
        int ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            dict[nums[i]]++;
            if(dict[nums[i]] > 1){
                ans = nums[i];
                break;
            }
        }
            
        
        return ans;
        
    }
};