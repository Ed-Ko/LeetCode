class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        int check = 1;
        Map<Character,Character> dict = new HashMap<Character,Character>();
        Map<Character,Character> dict2 = new HashMap<Character,Character>();
        
        for(int i = 0 ; i < s.length() ; i++){
            if(!dict.containsKey(s.charAt(i)))
                dict.put(s.charAt(i), t.charAt(i));
            else if(dict.get(s.charAt(i)) != t.charAt(i)){
                check = 0;
                break;
            }
            
            if(!dict2.containsKey(t.charAt(i)))
                dict2.put(t.charAt(i),s.charAt(i));
            else if(dict2.get(t.charAt(i)) != s.charAt(i)){
                check = 0;
                break;
            }
            
        }

        return check == 1 ? true : false;
        
        
    }
}