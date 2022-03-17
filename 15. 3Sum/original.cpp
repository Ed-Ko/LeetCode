class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        
        sort(nums.begin(),nums.end());

        for(int i = 0 ; i < nums.size() ; i++){
            
            int val = (-1 * nums[i]);
            map<int,int> dict;
            for(int j = 0 ; j < nums.size() && j < i ; j++){
                
                if(dict.find(val - nums[j]) != dict.end()){
                    vector<int> buf;
                    buf.insert(buf.end(), {nums[i], val - nums[j], nums[j]});
                    if((i != j) && (j != dict[val - nums[j]]) && (i != val - nums[j]))
                        ans.push_back(buf);
                }
                dict[nums[j]] = j;
            }
        }
        
        return ans;
    }
};