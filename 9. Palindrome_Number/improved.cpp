class Solution {
public:
    bool isPalindrome(int x) {    
        
        int ans = 0;
        int buf = x;
        
        if(x < 0)
            return false;

        while(buf > 0 && ans < (INT_MAX/10)){
            ans = (ans * 10) + (buf % 10);
            buf /= 10;
        }

        return (ans == x);
        
    }
};