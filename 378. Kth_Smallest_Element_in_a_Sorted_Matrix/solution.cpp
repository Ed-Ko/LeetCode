class Solution {
public:
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int ma_size = matrix.size();
        int ans = -1;
        
        int low = matrix[0][0];
        int high = matrix[ma_size - 1][ma_size - 1];
        
        while(low < high){
            
            int mid = low + (high - low) / 2;
            
            int small_count = 0;
            int upper = ma_size - 1;
            for(int i = 0 ; i < ma_size ; i++){
                while(upper >= 0 && matrix[i][upper] > mid)
                    upper--;
                small_count += (upper + 1);
            }
            
            if(small_count < k)
                low = mid + 1;
            else
                high = mid;
        }
        
        ans = low;
        return ans;
    }
};