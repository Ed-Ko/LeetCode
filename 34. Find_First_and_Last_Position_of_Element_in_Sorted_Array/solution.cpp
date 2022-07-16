class Solution {
public:
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int left = 0;
        int right = nums.size() - 1;
        
        vector<int> ans;
        
        if(nums.size() == 0 || right < left){
            ans.insert(ans.begin(), {-1,-1});
            return ans;
        }
             
        
        int mid = (left + right) / 2;
        while(left <= right){
            
            int mid = (left + right) / 2;
            //cout << nums[left] << " " << nums[right] << endl;
            //cout << left << " " << right << endl;
            if(left == right && nums[left] != target){
                ans.insert(ans.begin(), {-1,-1});
                break;
            }
            if(left == right - 1){
                
                if(nums[left] == target){
                    ans.push_back(left);
                    if(nums[right] == target)
                        ans.push_back(right);
                    else
                        ans.push_back(left);
                }
                else if(nums[right] == target)
                    ans.insert(ans.begin(), {right,right});
                else            
                    ans.insert(ans.begin(), {-1,-1});
                
                break;
            }
    
                
        
            if(nums[mid] == target){
                int i = mid;
                int j = mid;
                while(i - 1 >= 0 && nums[i-1] == nums[mid])
                    i--;
                while(j + 1 <= right && nums[j+1] == nums[mid])
                    j++;
                ans.insert(ans.begin(), {i,j});
                break;
            }

            else if(nums[mid] > target)
                right = mid;
            else
                left = mid;
        }
        
        return ans;
    }
};