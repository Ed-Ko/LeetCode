class Solution {
public:
    bool reorderedPowerOf2(int n) {
        
        string str_n = to_string(n);
        sort(str_n.begin(), str_n.end());
        
        long long multi = 1;
        for(int i = 0 ; i < 31 ; i++){
            string str_multi = to_string(multi);
            sort(str_multi.begin(), str_multi.end());
            if(str_n == str_multi)
                return true;
            multi *= 2;
        }
        return false;
        
    }
};