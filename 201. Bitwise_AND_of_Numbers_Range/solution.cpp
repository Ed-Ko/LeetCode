class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        int ans = 0;
        unsigned int zero_interval = 1;
        unsigned int multiplier = 1;
        
        for(int i = 0 ; i < 32; i++){
            //cout << ans << " " << multiplier << endl;
            if(right - left < zero_interval){
                if((left / zero_interval) % 2 && (right / zero_interval) % 2)
                    ans += multiplier;
            }
            multiplier *= 2;
            zero_interval *= 2;
        }
        
        return ans;
    }
};