class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long long left = 1;
        long long right = num;
        
        while(left <= right){
                
            long long mid = (left + right) / 2;
            
            //cout << mid << " ";
            
            if(mid * mid == num)
                return true;
            else if(mid * mid < num)
                left = mid;
            else
                right = mid;
            
            if(left == right - 1){
                if(left * left == num || right * right == num)
                    return true;
                else
                    break;
            }
            
        }
        
        return false;
    }
};