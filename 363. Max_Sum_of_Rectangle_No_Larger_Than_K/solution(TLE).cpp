class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        
        vector<vector<int>> dp(matrix.size() + 1, vector<int>(matrix[0].size(), 0));
        
        int ans = INT_MIN;
        
        for(int i = 1 ; i <= matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                dp[i][j] = matrix[i - 1][j] + dp[i - 1][j];
            }
        }
        
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = i + 1 ; j <= matrix.size() ; j++){
                
                for(int k = 0 ; k < matrix[0].size() ; k++){
                    int tmp_ans = 0;
                    for(int l = 0 ; k + l < matrix[0].size() ; l++){
                        tmp_ans += (dp[j][k + l] - dp[i][k + l]);
                        if(tmp_ans <= K && tmp_ans >= ans){
                            //cout << i << " " << j << " " << k << " " << l << " : " << tmp_ans << endl;
                            ans = tmp_ans;
                        }
                            
                    }
                    
                }
                
                
            }
        }
        
        return ans;
        
    }
};