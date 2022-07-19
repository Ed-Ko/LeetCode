class Solution {
public:
    int kInversePairs(int n, int k) {
        
        int limit = 1000000000 + 7;
        
        /*
        for(int i = 0 ; i <= n ; i++){
            int max_inverse = ((i - 1) * i) / 2;
            if(i == n && k > max_inverse)
                return 0;
            max_arr[i] = max_inverse;
        }
        */
        int dp[n + 1][k + 1];
        memset(dp, 0 ,sizeof(dp));
        dp[0][0] = 1;
        
        
        for(int i = 1 ; i <= n ; i++){
            long long sum = 0;
            for(int j = 0 ; j <=k ; j++){
                sum += dp[i-1][j];
                if(j >= i)
                    sum -= dp[i-1][j-i];
                dp[i][j] = sum % limit;
            }
        }
        /*
        for(int i = 0 ; i <= n ; i++){
            cout << i << " : ";
            for(int j = 0 ; j <= max_arr[n] ; j++)
                cout << dp[i][j] << " ";
            cout << endl;
        }
        */
        return dp[n][k];
        
    }
};