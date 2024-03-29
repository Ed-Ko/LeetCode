class Solution {
    public boolean isPowerOfThree(int n) {
        if(n == 1)
            return true;
        else if(n < 3)
            return false;
        
        while(n > 1){
            if(n % 3 == 0)
                n /= 3;
            else
                return false;
        }
        
        return n == 1 ? true : false;
    }
}