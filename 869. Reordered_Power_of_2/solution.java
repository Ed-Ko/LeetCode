class Solution {
    public boolean reorderedPowerOf2(int n) {
        
        String str_n = String.valueOf(n);
        char[] sorted_n = str_n.toCharArray();
        Arrays.sort(sorted_n);
        
        long multi = 1;
        for(int i = 1 ; i < 31 ; i++){
            String str_multi = String.valueOf(multi);
            char[] sorted_multi = str_multi.toCharArray();
            Arrays.sort(sorted_multi);
            
            if(Arrays.equals(sorted_n, sorted_multi))
                return true;
            
            multi *= 2;
            
        }
            
        return false;
        
    }
}