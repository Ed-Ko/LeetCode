class Solution {
public:
    
    vector<vector<int>> ans;
    
    void recur(vector<int>& nums, vector<int> cur_vec, int depth, int idx){
        
        cur_vec.push_back(nums[idx]);
        
        if(depth == 0){
            ans.push_back(cur_vec);
            return;
        }
        
        for(int i = idx + 1 ; i < nums.size() - depth + 1 ; i++){
            recur(nums, cur_vec, depth - 1, i);
        }
        
        return;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        ans.push_back({});
        
        for(int i = 1 ; i <= nums.size() ; i++){
            for(int j = 0 ; j < nums.size() ; j++){
                recur(nums, {}, i - 1, j);
            }
        }
        
        return ans;
        
    }
};