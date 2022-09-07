class Solution {
    public boolean isAnagram(String s, String t) {
        
        if(s.length() != t.length())
            return false;
        
        char[] sd = new char[26];
        char[] td = new char[26];
        
        for(int i = 0 ; i < s.length() ; i++){
            sd[s.charAt(i) - 'a']++;
            td[t.charAt(i) - 'a']++;
        }
        
        for(int i = 0 ; i < 26 ; i++){
            if(sd[i] != td[i])
                return false;
        }
        
        return true;
        
    }
}