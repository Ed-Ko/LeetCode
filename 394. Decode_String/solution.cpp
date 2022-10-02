class Solution {
public:
    
    string recur(string s){
        
        int left = 0;
        int right = 0;
        int start = 0;
        
        int st = 0;
    
        string final_return;
        
        while(right < s.length()){
            for(int i = start ; i < s.length() ; i++){
                if(s[i] == '['){
                    if(st == 0){
                        left = i;
                    }
                    st++;
                }
                else if(s[i] == ']'){
                    st--;
                    if(st == 0){
                        right = i;
                        break;
                    }
                }
                else{
                    if(0 <= s[i] - '0' && s[i] - '0' <= 9)
                        continue;
                    else if(st == 0)
                        final_return.push_back(s[i]);
                }
            }
            
            if(left == 0 && right == 0)
                return s;
            
            if(start == left)
                break;
            else{
                string sub = s.substr(left + 1, right - left - 1);
            
                string cur_return = recur(sub);
                
                int cur_sum = 0;
                int multi = 1;
                for(int i = 1 ; i <= 3 && left - i >= 0 && s[left - i] - '0' >= 0 && s[left - i] - '0' <= 9; i++){
                    cur_sum += (s[left - i] - '0') * multi;
                    multi *= 10;
                }
                for(int i = 0 ; i < cur_sum ; i++)
                    final_return += cur_return;
                
            }
            start = right + 1;
            left = start;
            right = start;
            
        }
        
        return final_return;
        
    }
    
    string decodeString(string s) {
        
        return recur(s);
        
    }
};