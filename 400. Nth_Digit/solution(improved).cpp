class Solution {
public:
    int findNthDigit(int n) {
        
        long long cur_len = 1;
        long long num_count = 9;
        long long start = 1;
        
        while(n > cur_len * num_count){
            n -= (cur_len * num_count);
            
            cur_len++;
            num_count *= 10;
            start *= 10;
        }
        
        start += ((n - 1) / cur_len);
        return to_string(start)[(n - 1) % cur_len] - '0';
        
    }
};