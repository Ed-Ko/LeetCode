class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        string ans = "";
        vector<char> stack;
        map<char, int> char_count;
        int fin['z'-'a'+1] = {0};
        
        for(int i = 0 ; i < s.length() ; i++){
            if(char_count.find(s[i]) == char_count.end())
                char_count[s[i]] = 1;
            else
                char_count[s[i]]++;
        }
        
        for(int i = 0 ; i < s.length() ; i++){
            
            char_count[s[i]]--;
            
            if(stack.size() == 0){
                stack.push_back(s[i]);
                fin[s[i]-'a'] = 1;
                continue;
            }
            
            if(fin[s[i]-'a'] != 0)
                continue;
            
            while(stack.size() != 0 && s[i] < stack.back() && char_count[stack.back()] > 0){
                fin[stack.back()-'a'] = 0;
                stack.pop_back();
                
            }
                
            stack.push_back(s[i]);
            fin[s[i]-'a'] = 1;
            
        }
            
        
        for(int i = 0 ; i < stack.size() ; i++)
            ans += stack[i];
        
        return ans;
    }
};