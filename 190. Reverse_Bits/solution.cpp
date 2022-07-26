class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0;
        
        for(int count = 1 ; count <= 32 ; count++){
            int release = n % 2;
            //cout << release << " ";
            ans = ans + release;
            if(count != 32)
                ans *= 2;
            n /= 2;
        }
                
        return ans;
        
        
    }
};