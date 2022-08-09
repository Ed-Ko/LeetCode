class NumArray {
public:
    
    vector<int> arr;
    int sum = 0;
    
    NumArray(vector<int>& nums) {
        arr = nums;
        
        for(int i = 0 ; i < nums.size() ; i++)
            sum += nums[i];
        
        
    }
    
    void update(int index, int val) {
        int dif = val - arr[index];
        sum += dif;
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        
        int left_sum = 0;
        for(int i = 0 ; i < left ; i++)
            left_sum += arr[i];
        int right_sum = 0;
        for(int i = right + 1 ; i < arr.size() ; i++)
            right_sum += arr[i];
        
        int ans = sum - left_sum - right_sum;
        return ans;
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */