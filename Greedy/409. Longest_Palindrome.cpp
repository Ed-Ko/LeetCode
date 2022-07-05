class Solution {
public:
    int longestPalindrome(string s) {
        
        int ans = 0;
        
        map<char, int> small_char_map;
        map<char, int> big_char_map;
        
        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] <= 'z' && s[i] >= 'a'){
                if(small_char_map.find(s[i]) == small_char_map.end())
                    small_char_map[s[i]] = 1;
                else
                    small_char_map[s[i]]++;
            }
            if(s[i] <= 'Z' && s[i] >= 'A'){
                if(big_char_map.find(s[i]) == big_char_map.end())
                    big_char_map[s[i]] = 1;
                else
                    big_char_map[s[i]]++;
            }
        }
        
        bool odd_appear = false;
        for(auto it = small_char_map.begin() ; it != small_char_map.end() ; it++){
            if(it->second % 2 == 1){
                odd_appear = true;
                ans += (it->second - 1);

            }
            else{
                ans += it->second;
            }
        }        
        
        for(auto it = big_char_map.begin() ; it != big_char_map.end() ; it++){
            if(it->second % 2 == 1){
                odd_appear = true;
                ans += (it->second - 1);
            }
            else{
                ans += it->second;
            }
        }
        if(odd_appear)
            ans++;
        
        return ans;
        
        
    }
};