 The API isBadVersion is defined for you.
 bool isBadVersion(int version);

class Solution {
public
    int firstBadVersion(int n) {
        
        
        long long left = 1;
        long long right = n;
        
        while(left = right){
            
            long long mid = (left + right)  2;
            
            if(isBadVersion(mid)){
                if(!isBadVersion(mid - 1))
                    return mid;
                else
                    right = mid - 1;
            }
            else
                left = mid + 1;
            
        }
        return -1;
    }
};