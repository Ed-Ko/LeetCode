class NumArray {
public:
    
    vector<int> arr;
    int sum_dp[30000][30000];
    
    NumArray(vector<int>& nums) {
        arr = nums;
        for(int i = 0 ; i < nums.size() ; i++){
            int cur_sum = nums[i];
            sum_dp[i][i] = nums[i];
            for(int j = i + 1 ; j < nums.size() ; j++){
                cur_sum += nums[j];
                sum_dp[i][j] = cur_sum;
            }
        }
        
    }
    
    void update(int index, int val) {
        
        int dif = val - arr[index];
        //cout << "update " << endl;
        for(int i = 0 ; i <= index ; i++)
            for(int j = index ; j < arr.size() ; j++)
                sum_dp[i][j] += dif;
            
        
        //cout << "==================" << endl;
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        return sum_dp[left][right];
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */