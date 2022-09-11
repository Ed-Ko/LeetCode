class Solution {
public:
    
    int var_window(string s, int k, int idx){
        
        int left = 0;
        char cur_ch = 'A' + idx;
        int cur_len = 0;
        
        int tmp_res = 0;
        
        for(int right = 0 ; right < s.length() ; right++){
            if(s[right] != cur_ch){
                s[right] = 'x';
                cur_len++;
            }
            
            while(cur_len > k){
                if(s[left] == 'x')
                    cur_len--;
                left++;
            }
            
            tmp_res = max(tmp_res, right - left + 1);
            
        }
        
        return tmp_res;
    }
    
    int characterReplacement(string s, int k) {
        
        int result = 0;
        
        for(int i = 0 ; i < 26 ; i++)
            result = max(result, var_window(s, k, i));
        
        return result;
    }
};