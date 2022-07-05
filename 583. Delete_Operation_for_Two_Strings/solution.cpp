class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int dp[word1.length() + 1][word2.length() + 1];
        
        for(int i = 0 ; i < word1.length() + 1 ; i++)
            for(int j = 0 ; j < word2.length() + 1 ; j++)
                dp[i][j] = 0;
        
        for(int i = word1.length() - 1 ; i >= 0 ; i--){
            for(int j = word2.length() - 1 ; j >= 0 ; j--){
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i+1][j+1] + 1;
                else
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        
        return word1.length() + word2.length() - 2*dp[0][0];
        
    }
};