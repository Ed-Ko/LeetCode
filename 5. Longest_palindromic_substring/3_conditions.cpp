class Solution {
public:
    string longestPalindrome(string s) {
        string sub = "";
        string max_sub = "";

        if(s.length() == 1){
            string temp = "";
            temp.push_back(s[0]);
            return temp;
        }
        else{
            for(int i = 1 ; i < s.length() - 1 ; i++){
                if(s[i-1] == s[i+1] && i + 1 < s.length() && i - 1 >= 0){
                    int tmp = 1;
                    sub += s[i];
                    while( i - tmp >= 0 && i + tmp < s.length() && s[i-tmp] == s[i+tmp]){
                        ///cout << " ------- " << sub << endl;
                        sub = s[i-tmp] + sub + s[i+tmp];
                        tmp++;
                    }
                    if(sub.length() > max_sub.length())
                        max_sub = sub;
                    sub = "";
                }

            }
            if(max_sub.length() == 0)
                max_sub += s[0];
            ///cout << " ------- " << max_sub << endl;
            for(int i = 1 ; i < s.length() - 1 ; i++){
                if(s[i] == s[i-1] && i - 1 >= 0 ){
                    ///cout << i << endl;
                    int tmp = 1;
                    sub = sub + s[i-1] + s[i];
                    while( i - tmp - 1 >= 0 && i + tmp < s.length() && s[i-tmp-1] == s[i+tmp]){
                        ///cout << " ======= " << sub << endl;
                        sub = s[i-tmp-1] + sub + s[i+tmp];
                        tmp++;
                    }
                    if(sub.length() > max_sub.length())
                        max_sub = sub;
                    sub = "";
                }
            }
            
            ///cout << " ======= " << max_sub << endl;
            
            for(int i = 0 ; i < s.length() - 1 ; i++){
                sub += s[i];
                while( i + 1 < s.length() && s[i] == s[i+1]){
                   ///cout << " -=-=-=- " << sub << endl;
                   sub = sub + s[i+1];
                   i++;
                }
                if(sub.length() > max_sub.length())
                    max_sub = sub;
                sub = "";
                
            }
            
            ///cout << " -=-=-=- " << max_sub << endl;
        }

        ///cout << max_sub << endl;
        return max_sub;
    }
};