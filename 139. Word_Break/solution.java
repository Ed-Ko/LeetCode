class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        
        boolean[] dp = new boolean[s.length() + 1];
        Arrays.fill(dp, false);
        dp[0] = true;
        
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = 0 ; j < wordDict.size() ; j++){
                if(dp[i]){
                    String cur_sub = wordDict.get(j);
                    String main_sub;
                    if(i + cur_sub.length() <= s.length())
                        main_sub = s.substring(i, i + cur_sub.length());
                    else
                        main_sub = s.substring(i, s.length());
                    
                    if(cur_sub.equals(main_sub))
                        dp[i + main_sub.length()] = true;

                }
                
            }
        }

        
        return dp[s.length()];
        
    }
}