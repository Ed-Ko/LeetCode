class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(i > 0 && nums[i-1] == nums[i])
                continue;
            
            long long buf = target - nums[i];
            
            for(int j = i+1 ; j < nums.size() ; j++){
                
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                
                long long cur_dif = buf - nums[j];
                
                int left = j+1;
                int right = nums.size()-1;
                
                while(left < right){
                    if(cur_dif < nums[left] + nums[right])
                        right--;
                    else if(cur_dif > nums[left] + nums[right])
                        left++;
                    else{
                        //cout << left << " " << right << endl;
                        vector<int> tmp;
                        tmp.insert(tmp.begin(), {nums[i],nums[j],nums[left],nums[right]});
                        ans.push_back(tmp);
                        while(left < right && nums[left] == nums[left+1])
                            left++;
                        while(right > left && nums[right] == nums[right-1])
                            right--;
                        
                        left++;
                        right--;
                    }
                }
                
                
            }
            
        }
        
        return ans;
        
    }
};