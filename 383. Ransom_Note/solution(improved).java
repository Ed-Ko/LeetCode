class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        
        Map<Character,Integer> ran_map = new HashMap<Character,Integer>();
        
        for(int i = 0 ; i < ransomNote.length() ; i++){
            if(ran_map.containsKey(ransomNote.charAt(i))){
                int old_val = ran_map.get(ransomNote.charAt(i));
                ran_map.replace(ransomNote.charAt(i), old_val + 1);
            }
            else
                ran_map.put(ransomNote.charAt(i), 1);
        }
        
        for(int i = 0 ; i < magazine.length() ; i++){
            if(ran_map.containsKey(magazine.charAt(i))){
                int old_val = ran_map.get(magazine.charAt(i));
                ran_map.replace(magazine.charAt(i), old_val - 1);
            }
            else
                ran_map.put(magazine.charAt(i), - 1);
        }
        
        
        for(Map.Entry<Character,Integer> entry_now : ran_map.entrySet()){
            
            if(entry_now.getValue() > 0)
                return false;
        }
        
        return true;
    }
}