class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        
        vector<int> vec1;
        vector<int> vec2;
        
        if(nums.size() == 1)
            return 0;
        
        vec1.push_back(nums[0]);
        for(int i = 1 ; i < nums.size() ; i++)
            vec1.push_back(max(vec1[i-1], nums[i]));
        
        vec2.push_back(nums[nums.size()-1]);
        for(int i = nums.size() - 2 ; i >= 0 ; i--)
            vec2.insert(vec2.begin(), min(vec2.front(), nums[i]));
        
        
        
        int i = 0;
        int j = nums.size() - 1;
        while(i < nums.size() && vec1[i] == vec2[i])
            i++;
        while(j >= 0 && vec1[j] == vec2[j])
            j--;
        
        if(i < j)
            return j-i+1;
        else
            return 0;
        
    }
};