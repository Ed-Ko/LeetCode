class Solution {
public:
    int findNthDigit(int n) {
        
        long long cur_count = 0;
        int cur_size = 1;
        int cur_scope = 10;
        int cur_num;
        
        for(int i = 1 ; i <= n ; i++){
            if(i >= cur_scope){
                cur_size++;
                cur_scope *= 10;
            }
            
            cur_count += cur_size;
            
            if(cur_count >= n){
                cur_num = i;
                break;
            }
                
        }
        
        while(cur_num > 0){
            if(cur_count > n){
                cur_num /= 10;
                cur_count--;
            }
            else
                break;
        }
        
        return cur_num % 10;
        
    }
};