class Solution {
public:
    bool isHappy(int n) {
        
        bool ans = true;
        map<int,int> dict;
        
        while(n != 1){
            int cur_sum = 0;
            while(n > 0){
                cur_sum += pow((n % 10), 2);
                
                n /= 10;
            }
            if(dict.find(cur_sum) == dict.end())
                dict[cur_sum] = 1;
            else{
                //cout << cur_sum << endl;
                ans = false;
                break;
            }
                
            n = cur_sum;
            
        }
        
        return ans;
    }
};