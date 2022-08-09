class Solution {
public:
    
    bool test_cut(vector<int>& nums, int split_num, int mid){
        
        int tmp = 0;
        int cut_count = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(tmp + nums[i] <= mid)
                tmp += nums[i];
            else{
                tmp = nums[i];
                cut_count++;
            }
        }
        
        if(tmp < mid)
            cut_count++;
        
        if(cut_count <= split_num)
            return true;
        
        return false;
        
    }
    
    int splitArray(vector<int>& nums, int m) {
        
        int ans = 0;
        
        
        int lower = 0;
        int upper = 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            upper += nums[i];
            if(nums[i] > lower)
                lower = nums[i];
        }
        
        while(lower <= upper){
            
            int mid = lower + (upper - lower) / 2;
            
            if(test_cut(nums, m, mid)){
                ans = mid;
                upper = mid - 1;
            }
            else
                lower = mid + 1;
            
        }
        
        return ans;
        
    }
};