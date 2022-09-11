class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        
        int dict[26];
        int comp[26];
        memset(dict, 0, sizeof(dict));
        memset(comp, 0, sizeof(comp));
        vector<int> ans;
        
        if(s.length() < p.length())
            return{};
        
        for(int i = 0 ; i < p.length() ; i++){
            dict[s[i] - 'a']++;
            comp[p[i] - 'a']++;
        }
        
        int check = 1;
        for(int i = 0 ; i < 26 ; i++){
            if(dict[i] != comp[i]){
                check = 0;
                break;
            }
        }
        if(check)
            ans.push_back(0);
        
        for(int i = 0 ; i + p.length() < s.length() ; i++){
            dict[s[i + p.length()] - 'a']++;
            dict[s[i] - 'a']--;
            
            int check2 = 1;
            for(int j = 0 ; j < 26 ; j++){
                if(dict[j] != comp[j]){
                    check2 = 0;
                    break;
                }
            }
            if(check2)
                ans.push_back(i + 1);
        }
        
        
        return ans;
            
        
        
    }
};