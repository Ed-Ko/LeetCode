class Solution {
public:
    bool isIsomorphic(string s, string t) {

        int check = 1;
        unordered_map<int,int> dict;
        unordered_map<int,int> dict2;
        
        for(int i = 0 ; i < s.length() ; i++){
            if(dict.find(s[i]) == dict.end())
                dict[s[i]] = t[i];
            else if(dict[s[i]] != t[i]){
                check = 0;
                break;
            }
            
            if(dict2.find(t[i]) == dict2.end())
                dict2[t[i]] = s[i];
            else if(dict2[t[i]] != s[i]){
                check = 0;
                break;
            }
            
        }

        return check == 1 ? true : false;
        
    }
};