class Solution {
public:
    string convert(string s, int numRows) {
        
    string ans = "";
    
    if(numRows >= s.length() || numRows == 1)
        return s;
        
    for(int i = 0 ; i < numRows && i < s.length() ; i++){
        ///cout << i << " " << ans << endl;
        if(i == 0 || i == numRows - 1){
            ans += s[i];
            for(int j = i + ( 2 * (numRows - 1)) ; j < s.length() ;){
                ans += s[j];
                j += ( 2 * (numRows - 1));
            }
        }
        
        else{
            ans += s[i];
            int idx = i;
            int new_idx = i;
            
            while(1){
                ///cout << idx + (2 * (numRows-1) - 2 * i) << " ";
                
                if(idx + (2 * (numRows-1) - 2 * i) < s.length()){
                    new_idx += (2 * (numRows-1) - 2 * i);
                    ans += s[new_idx];
                }
                else
                    break;
                
                
                if(idx + (2 * (numRows-1)) < s.length()){
                    new_idx += 2*i;
                    ans += s[new_idx];
                }
                else
                    break;
                    
                idx = new_idx;
            }
        }
        
    }
    
    return ans;
    }
};