class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        string tmp1 = "";
        string tmp2 = "";
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == '#'){
                if(tmp1 != "")
                    tmp1.pop_back();
            }
            else
                tmp1.push_back(s[i]);
        }
        for(int i = 0 ; i < t.length() ; i++){
            if(t[i] == '#'){
                if(tmp2 != "")
                    tmp2.pop_back();
            }
                
            else
                tmp2.push_back(t[i]);
        }
        
        return tmp1 == tmp2;
    }
};