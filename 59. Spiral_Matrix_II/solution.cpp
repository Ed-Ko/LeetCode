class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int i = 0;
        int j = 0;
        int dir = 1;
        int right = n - 1;
        int left = 0;
        int up = 1;
        int down = n - 1;
        for(int a = 1 ; a <= n*n ; a++){
            switch(dir){
                case 1:
                    ans[i][j] = a;
                    if(j + 1 > right){
                        dir = 2;
                        i++;
                        right--;
                    }
                    else
                        j++;
                    
                    break;
                case 2:
                    ans[i][j] = a;
                    
                    if(i + 1 > down){
                        dir = 3;
                        j--;
                        down--;
                    }
                    else
                        i++;
                    
                    break;
                case 3:
                    ans[i][j] = a;
                    
                    if(j - 1 < left){
                        dir = 4;
                        i--;
                        left++;
                    }
                    else
                        j--;
                    
                    break;
                case 4:
                    ans[i][j] = a;
                    
                    if(i - 1 < up){
                        dir = 1;
                        j++;
                        up++;
                    }
                    else
                        i--;
                    
                    break;
            }
            
            
            
        }
        return ans;
    }
};