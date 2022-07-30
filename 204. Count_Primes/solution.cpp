class Solution {
public:
    int countPrimes(int n) {
        
        int arr[n + 1];
        int ans = 0;
        
        for(int i = 2 ; i <= n ; i++)
            arr[i] = 1;
        
        for(int i = 2 ; i < n ; i++){
            if(arr[i]){
                for(int j = i + i ; j <= n ; j += i)
                    arr[j] = 0;
            }
        }
        
        
        for(int i = 2 ; i < n ; i++){
            if(arr[i])
                ans++;
        }
        
        return ans;
        
        
    }
};