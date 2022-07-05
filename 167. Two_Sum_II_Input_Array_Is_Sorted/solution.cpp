class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans;
        int left = 0;
        int right = numbers.size()-1;
        
        while(left < right){
            if(target < numbers[left] + numbers[right])
                right--;
            else if(target > numbers[left] + numbers[right])
                left++;
            else
                break;
        }
        ans.insert(ans.begin(), {left+1,right+1});
        return ans;
    }
};