class Solution {
public:
    
    int recur(string s, int idx, vector<int>& dp){
        
        if(idx == 0){
            if(s[idx] == '0')
                return 0;
            else
                return 1;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int cur_val = 0;
        
        char first = ' ';
        char second = s[idx];
        if(idx - 1 < s.length())
            first = s[idx - 1];
        
        if(second != '0')
            cur_val += recur(s, idx - 1, dp);
        
        if(idx - 1 >= 0 && first == '1' || (first == '2' && second <= '6')){
            if(idx - 2 < 0)
                cur_val++;
            else
                cur_val += recur(s, idx - 2, dp);
                
        }
        
        dp[idx] = cur_val;
        return cur_val;
        
    }
    
    int numDecodings(string s) {

        vector<int> dp(s.length(), -1);

        return recur(s, s.length() - 1, dp);
        
    }
};