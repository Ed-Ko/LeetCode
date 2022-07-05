class Solution {
public:
    string reverseWords(string s) {
        string ans;
        string tmp_str;
        int left = 0;
        int right = 1;
        for(int i = 0 ; i < s.length() ; i++){
            
            if(s[s.length() - 1 - i] != ' ')
                tmp_str.push_back(s[s.length() - 1 - i]);
            
            else{
                ans.insert(0, tmp_str);
                ans.insert(0, " ");
                tmp_str = "";
            }
        }
        ans.insert(0, tmp_str);
        tmp_str = "";
        return ans;
    }
};