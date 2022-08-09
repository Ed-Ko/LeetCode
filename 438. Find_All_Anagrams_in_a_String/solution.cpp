class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        map<char,int> dict;
        map<char,int> comp;
        vector<int> ans;
        
        if(s.length() < p.length())
            return{};
        
        for(int i = 0 ; i < p.length() ; i++){
            dict[s[i]]++;
            comp[p[i]]++;
        }
        
        int check = 1;
        for(auto it = comp.begin() ; it != comp.end() ; it++){
            if(dict.find(it->first) == dict.end() || dict[it->first] != it->second){
                check = 0;
                break;
            }
        }
        if(check)
            ans.push_back(0);
        
        for(int i = 0 ; i + p.length() - 1 < s.length() ; i++){
            dict[s[i + p.length()]]++;
            dict[s[i]]--;
            
            if(comp.find(s[i]) == comp.end())
                comp[s[i]] = 0;
            
            if(comp == dict)
                ans.push_back(i + 1);
        }
        
        
        return ans;
            
        
        
    }
};