class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int front_product[1000000];
        int back_product[1000000];
        vector<int> ans;
        
        
        int cur_multi = 1;
        for(int i = 0 ; i < nums.size() ; i++){
            cur_multi *= nums[i];
            front_product[i] = cur_multi;
        }
        
        cur_multi = 1;
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            cur_multi *= nums[i];
            back_product[i] = cur_multi;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(i == 0)
                ans.push_back(back_product[i + 1]);
            else if(i == nums.size() - 1)
                ans.push_back(front_product[i - 1]);
            else
                ans.push_back(front_product[i - 1] * back_product[i + 1]);
        }
        
        return ans;
    }
};