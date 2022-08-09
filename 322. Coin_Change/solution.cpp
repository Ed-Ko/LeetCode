class Solution {
public:
    
    int dp[10002];
    
    int recur(vector<int>& coins, int amount){
        
        if(amount == 0)
            return 0;
        
        if(dp[amount] != -1)
            return dp[amount];
        
        int final_res = INT_MAX;
        
        for(int i = 0 ; i < coins.size() ; i++){
            if(amount - coins[i] >= 0){
                int cur_res = recur(coins, amount - coins[i]);
                if(final_res > cur_res + 1LL)
                    final_res = cur_res + 1;
                    
            }
            
        }
        dp[amount] = final_res;
        return final_res;
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        sort(coins.begin(), coins.end());
        
        memset(dp, -1, sizeof(dp));
        
        int ans = recur(coins, amount);
        if(ans == INT_MAX)
            return -1;
        return ans;
        
    }
};