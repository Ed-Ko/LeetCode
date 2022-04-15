class Solution {
public:
    int uniquePaths(int m, int n) {
        int dp_mat[m][n];

        dp_mat[0][0] = 0;

        for(int i = 0 ; i < m ; i++)
            dp_mat[i][0] = 1;

        for(int i = 0 ; i < n ; i++)
            dp_mat[0][i] = 1;


        for(int i = 1 ; i < m ; i++){
            for(int j = 1 ; j < n ; j++){
                dp_mat[i][j] = dp_mat[i-1][j] + dp_mat[i][j-1];
            }
        }
        
        return dp_mat[m-1][n-1];
    }
};