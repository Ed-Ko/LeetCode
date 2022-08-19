class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int left = 0;
        int right = left;
        
        int ans = INT_MAX;
        
        int cur_sum = 0;
        
        while(right < nums.size()){
            
            cur_sum += nums[right];
            
 
            while(cur_sum >= target){
                //cout << left << " " << right << " : " << cur_sum << endl;
                ans = min(ans, right - left + 1);
                cur_sum -= nums[left];
                left++;
            }
                
            
            right++;
        }
        
        if(ans != INT_MAX)
            return ans;
        return 0;
    }
};