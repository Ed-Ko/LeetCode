class Solution {
public:
    int uniquePaths(int m, int n) {
        int ans;
        long long int up = 1;
        long long int down = 1;
        int check = 1;
        
        for(int i = 1 ; i <= min(m-1, n-1) ; i++)
            down *= i;
        for(int i = (m+n-2) ; i > max(m-1, n-1) ; i--){
            up *= i;
            if((check == 1) && (up % down == 0)){
                up /= down;
                check = 0;
            }
        }
        ans = up;
        
        return ans;
    }
};