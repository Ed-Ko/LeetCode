class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        
        int row_num = matrix.size();
        int col_num = matrix[0].size();
        
        int tmp[row_num + 1][col_num];
        memset(tmp, 0, sizeof(tmp));
        
        int ans = 0;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            for(int j = 0 ; j < matrix[0].size() ; j++){
                tmp[i + 1][j] = matrix[i][j] + tmp[i][j];
            }
        }
        
        for(int i = 0 ; i < row_num ; i++){
            for(int j = i + 1 ; j <= row_num ; j++){
                for(int k = 0 ; k < col_num ; k++){
                    long long sum = 0;
                    for(int l = k ; l < col_num ; l++){
                        sum = sum + tmp[j][l] - tmp[i][l];
                        
                        if(sum == target)
                            ans++;
                    }
                }
                
            }
        }
        return ans;
        
    }
};