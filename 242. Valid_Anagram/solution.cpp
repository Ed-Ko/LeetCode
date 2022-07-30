class Solution {
public:
    bool isAnagram(string s, string t) {
        
        map<char,int> s_dict;
        map<char,int> t_dict;
        
        if(s.length() != t.length())
            return false;
        
        for(int i = 0 ; i < s.length() ; i++){
            s_dict[s[i]]++;
            t_dict[t[i]]++;
        }
        
        bool ans = true;
        for(auto it = t_dict.begin() ; it != t_dict.end() ; it++){
            if(it->second != s_dict[it->first] || s_dict.find(it->first) == s_dict.end()){
                //cout << it->first << endl;
                ans = false;
                break;
            }
        }
        
        return ans;
    }
};