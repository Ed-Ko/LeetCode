class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        
        if(k == 0)
            return 0;
        
        vector<vector<int>> dp(k + 1, vector<int>(2, 0));
        for(int i = 0 ; i <= k ; i++)
            dp[i][0] = INT_MAX;
        
        for(int i = 0 ; i < prices.size() ; i++){
            for(int j = 1 ; j <= k ; j++){
                
                dp[j][0] = min(dp[j][0], prices[i] - dp[j - 1][1]);
                
                dp[j][1] = max(dp[j][1], prices[i] - dp[j][0]);
                
            }
            
        }
        
        return dp[k][1];
        
    }
};