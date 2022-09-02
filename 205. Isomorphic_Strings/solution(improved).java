class Solution {
    public boolean isIsomorphic(String s, String t) {
        
        int check = 1;
        int[] dict = new int[256];
        int[] dict2 = new int[256];
        Arrays.fill(dict, 0);
        Arrays.fill(dict2, 0);
        
        char[] ss = s.toCharArray();
        char[] st = t.toCharArray();
        
        for(int i = 0 ; i < s.length() ; i++){
            if(dict[ss[i]] == 0)
                dict[ss[i]] = st[i];
            else if(dict[ss[i]] != st[i]){
                check = 0;
                break;
            }
            
            if(dict2[st[i]] == 0)
                dict2[st[i]] = ss[i];
            else if(dict2[st[i]] != ss[i]){
                check = 0;
                break;
            }
            
        }

        return check == 1 ? true : false;
        
        
    }
}