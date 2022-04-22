class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        map<int, int> dict;
        
        dict[0] = 0;
        dict[1] = 0;
        dict[2] = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
            dict[nums[i]]++;
        
        for(int i = 0 ; i <= 2 ; i++){
            for(int j = 0 ; j < dict[i] ; j++){
                nums.erase(nums.begin());
                nums.push_back(i);
            }
        }
    }
};