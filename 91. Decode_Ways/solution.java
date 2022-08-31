class Solution {
    
    public int recur(String s, int idx, int[] dp){
        
        if(idx == 0){
            if(s.charAt(idx) == '0')
                return 0;
            else
                return 1;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int cur_val = 0;
        
        Character first = ' ';
        Character second = s.charAt(idx);
        if(idx - 1 < s.length())
            first = s.charAt(idx - 1);
        
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
    
    public int numDecodings(String s) {
        
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        
        return recur(s, s.length() - 1, dp);
        
    }
}