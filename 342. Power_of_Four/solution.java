class Solution {
    public boolean isPowerOfFour(int n) {
        
        if(n == 1)
            return true;
        else if(n < 4)
            return false;
        
        
        while(n > 1){
            if(n % 4 == 0)
                n /= 4;
            else
                return false;
        }
        return n == 1 ? true : false;
    }
}