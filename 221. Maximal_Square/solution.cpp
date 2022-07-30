class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int dp[matrix.size()][matrix[0].size()];
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                    dp[i][j] = 1;
            }
        }
        
        for(int i = 1 ; i < matrix.size() ; i++){
            for(int j = 1 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == '1')
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
        
        int max_edge = INT_MIN;
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(max_edge < dp[i][j])
                    max_edge = dp[i][j];
            }
        }
        
        
        return max_edge * max_edge;
        
    }
};