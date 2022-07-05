class Solution {
public:
    void reverseString(vector<char>& s) {
        vector<char> buf;
        for(int i = 0 ; i < s.size() ; i++)
            buf.push_back(s[s.size()-1-i]);
        s = buf;
        return;
    }
};