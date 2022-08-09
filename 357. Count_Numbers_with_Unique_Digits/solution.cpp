class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        long long ans = 0;
        
        if(n == 0)
            return 1;
        
        long long factorial[10];
        factorial[0] = 1;
        for(int i = 1 ; i < 10 ; i++)
            factorial[i] = factorial[i - 1] * (i + 1);
        
        
        for(int i = 1 ; i <= n ; i++){
            if(i == 1)
                ans += 10;
            else
                ans += (factorial[9] / factorial[9 - i]) - (factorial[8] / factorial[8 - i + 1]);
            
            //cout << i << " " << (factorial[9] / factorial[8 - i]) << " - " << (factorial[8] / factorial[8 - i + 1]) << endl;
        }
        
        
        return ans;
        
    }
};