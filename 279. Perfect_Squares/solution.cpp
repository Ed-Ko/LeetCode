class Solution {
public:
    
    int recur(int cur_div, vector<int>& dp){
        
        if(cur_div == 0)
            return 0;
        
        if(dp[cur_div] != -1)
            return dp[cur_div];
        
        int cur_min = cur_div;
        
        for(int i = 1 ; i * i <= cur_div ; i++){
            int tmp_result = recur(cur_div - i * i, dp);
            if(tmp_result + 1 < cur_min)
                cur_min = tmp_result + 1;   
        }
        
        dp[cur_div] = cur_min;
        
        return cur_min;
    }
    
    
    int numSquares(int n) {
        
        vector<int> dp(n+1, -1);
        
        return recur(n, dp);
    }
};