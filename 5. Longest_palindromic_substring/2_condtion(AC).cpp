class Solution {
public:
    string longestPalindrome(string s) {
        string sub = "";
    string max_sub = "";

    int total_len = 0;
    int start = 0;

    if(s.length() == 1){
        return s;
    }
    else{
        for(int i = 1 ; i < s.length() ; i++){

            if(s[i-1] == s[i+1] && i + 1 < s.length() && i - 1 >= 0){
                int tmp = 1;
                sub += s[i];
                while( i - tmp >= 0 && i + tmp < s.length() && s[i-tmp] == s[i+tmp]){
                    ///cout << " ------- " << sub << endl;
                    tmp++;
                }
                total_len = 2*(tmp-1) + 1;
                start = i - tmp + 1;
                if(total_len > max_sub.length())
                    max_sub = s.substr(start,total_len);
                
            }
            sub = "";
            total_len = 0;
            start = 0;
            if(s[i] == s[i-1] && i - 1 >= 0){
                int tmp = 1;
                sub = s[i] + sub + s[i-1];
                while( i - tmp - 1 >= 0 && i + tmp < s.length() && s[i-tmp-1] == s[i+tmp]){
                    ///cout << " ------- " << sub << endl;
                    tmp++;
                }
                total_len = 2*(tmp-1) + 2;
                start = i - tmp;                if(total_len > max_sub.length())
                    max_sub = s.substr(start,total_len);
            }
            sub = "";
            total_len = 0;
            start = 0;
        }
        if(max_sub == "")
            max_sub.push_back(s[0]);
    }

    ///cout << max_sub << endl;
    return max_sub;
    }
};