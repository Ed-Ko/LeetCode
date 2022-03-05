class Solution {
public:
    bool isPalindrome(int x) {    
        string s = "";

        if(x < 0)
            s += "-";

        while(x != 0){
            char ch = (char)(x%10);
            s += ch;
            x /= 10;
        }

        int check = 1;
        for(int i = 0 ; i < (s.length()/2) ; i++){
            if(s[i] != s[s.length() - i - 1]){
                check = 0;
                break;
            }
        }

        if(check == 1)
            return true;
        else
            return false;
    }
};