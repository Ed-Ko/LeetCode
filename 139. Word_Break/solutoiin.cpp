class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int dp[300];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for(int i = 0 ; i <= s.length() ; i++){
            for(int j = 0 ; j < wordDict.size() ; j++){
                if(dp[i]){
                    string cur_sub = wordDict[j];
                    string main_sub = s.substr(i, cur_sub.length());
                    if(cur_sub == main_sub){
                        dp[i + cur_sub.length()] = 1;
                    }
                }
                
                    
            }
        }

        
        return dp[s.length()];
        
    }
};