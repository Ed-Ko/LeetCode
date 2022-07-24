class Solution {
public:
    int trailingZeroes(int n) {
        
        int zero_count = 0;
        
        for(int i = 5 ; n / i >= 1 ; i *= 5){     
            zero_count += (n / i);
        }
        
        return zero_count;
        
    }
};