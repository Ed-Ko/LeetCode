class Solution {
    public boolean isPowerOfFour(int n) {
        
        boolean check2 = (n & (n - 1)) == 0 ? true : false;
        
        boolean check3 = (n & 1431655765) == 0 ? false : true;
            
        return (n > 0) && check2 && check3;
        
    }
}