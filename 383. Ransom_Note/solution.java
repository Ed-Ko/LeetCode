class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        
        Map<Character,Integer> ran_map = new HashMap<Character,Integer>();
        Map<Character,Integer> mag_map = new HashMap<Character,Integer>();
        
        for(int i = 0 ; i < ransomNote.length() ; i++){
            if(ran_map.containsKey(ransomNote.charAt(i))){
                int old_val = ran_map.get(ransomNote.charAt(i));
                ran_map.replace(ransomNote.charAt(i), old_val + 1);
            }
            else
                ran_map.put(ransomNote.charAt(i), 1);
        }
        
        for(int i = 0 ; i < magazine.length() ; i++){
            if(mag_map.containsKey(magazine.charAt(i))){
                int old_val = mag_map.get(magazine.charAt(i));
                mag_map.replace(magazine.charAt(i), old_val + 1);
            }
            else
                mag_map.put(magazine.charAt(i), 1);
        }
        
        //System.out.println(mag_map.size());
        //System.out.println(ran_map.size());
        
        for(Map.Entry<Character,Integer> entry_now : ran_map.entrySet()){
            
            if(mag_map.containsKey(entry_now.getKey()) == false || entry_now.getValue() > mag_map.get(entry_now.getKey()) )
                return false;
        }
        
        return true;
    }
}