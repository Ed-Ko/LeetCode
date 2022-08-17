class Solution {
    public int firstUniqChar(String s) {
        
        int ans = Integer.MAX_VALUE;
        
        Map<Character,Integer> dict = new TreeMap<>();
        
        for(char c = 'a' ; c <= 'z' ; c++){
            
            int tmp = s.indexOf(c);
            
            if(tmp != -1 && tmp == s.lastIndexOf(c))
                ans = Math.min(ans, tmp);
            
        }
        
        
        if(ans == Integer.MAX_VALUE)
            return -1;
        
        return ans;
    }
}