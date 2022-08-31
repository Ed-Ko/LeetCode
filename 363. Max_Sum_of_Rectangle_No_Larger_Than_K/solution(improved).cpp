class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {        
        
        int ans = INT_MIN;
        
        for(int left = 0 ; left < matrix[0].size() ; left++){ // left bound
            
            int arr[matrix.size()];
            memset(arr, 0, sizeof(arr));
            
            for(int right = left ; right < matrix[0].size() ; right++){ // right bound
                
                for(int tmp_row = 0 ; tmp_row < matrix.size() ; tmp_row++) // dp
                    arr[tmp_row] += matrix[tmp_row][right];
                
                int sum = 0; // current sum of this rectangle
                int max_sum = INT_MIN; // max sum of this rectangle
                
                for(int i = 0 ; i < matrix.size() ; i++){
                    sum = max(sum + arr[i], arr[i]);
                    max_sum = max(max_sum, sum);
                    if(max_sum == K) // this rectangle can reach K
                        return K;
                }
                if(max_sum < K) // update max sum 
                    ans = max(ans, max_sum);
                else{ // this rectangle can grow larger than K, probing the largest one but less than K
                    
                    for(int i = 0 ; i < matrix.size() ; i++){
                        int sum = 0;
                        for(int j = i ; j < matrix.size() ; j++){
                            sum += arr[j];
                            if(sum <= K)
                                ans = max(ans, sum);
                        }
                        if(ans == K)
                            return K;
                    }
                    
                }
                    
                
                
            }    
            
        }
        
        return ans;
        
    }
};