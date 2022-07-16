class Solution {
public:
    
    int dp[51][51][52];
    int mod = 1000000007;
    int row_num;
    int col_num;
    long long int recur(int r, int c, int moves){
        
        if((r < 0 || c < 0 || r >= row_num || c >= col_num) && (moves >= 0))
            return 1;
        if(moves <= 0)
            return 0;
        
        if(dp[r][c][moves] != -1)
            return dp[r][c][moves];
        
        long long ans = recur(r+1, c, moves-1) + recur(r-1, c, moves-1) + recur(r, c+1, moves-1) + recur(r, c-1, moves-1);
        
        return dp[r][c][moves] = ans % mod;
        
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
        row_num = m;
        col_num = n;
        memset(dp, -1, sizeof(dp));
        
        return recur(startRow, startColumn, maxMove);
        
    }
};