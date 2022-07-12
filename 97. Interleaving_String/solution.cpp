class Solution {
public:
    
    bool recur(string s1, string s2, string s3, int idx1, int idx2, int idx3){
        
        if(idx1 + idx2 == s3.length())
            return true;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        bool cur_ans = false;
            
        if(idx1 < s1.length() && s1[idx1] == s3[idx3])
            cur_ans |= recur(s1, s2, s3, idx1 + 1, idx2, idx3 + 1);
        
        if(idx2 < s2.length() && s2[idx2] == s3[idx3])
            cur_ans |= recur(s1, s2, s3, idx1, idx2 + 1, idx3 + 1);
        
        dp[idx1][idx2] = cur_ans;
        
        return cur_ans;
        
    }
    
    int dp[101][101];
    
    bool isInterleave(string s1, string s2, string s3) {
        
        if(s3.length() != s1.length() + s2.length())
            return false;
        
        memset(dp, -1, sizeof(dp));
        
        bool ans = recur(s1, s2, s3, 0, 0, 0);
        
        return ans;
    }
};