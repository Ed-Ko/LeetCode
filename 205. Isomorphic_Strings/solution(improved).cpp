class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int check = 1;
        vector<int> dict(256, '\0');
        vector<int> dict2(256, '\0');
        
        for(int i = 0 ; i < s.length() ; i++){
            if(dict[s[i]] == '\0')
                dict[s[i]] = t[i];
            else if(dict[s[i]] != t[i]){
                check = 0;
                break;
            }
            
            if(dict2[t[i]] == '\0')
                dict2[t[i]] = s[i];
            else if(dict2[t[i]] != s[i]){
                check = 0;
                break;
            }
            
        }

        return check == 1 ? true : false;
        
    }
};