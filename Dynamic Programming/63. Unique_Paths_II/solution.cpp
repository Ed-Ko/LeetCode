class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        int dp_mat[m][n];


        for(int i = 0 ; i < obstacleGrid.size() ; i++){
            for(int j = 0 ; j < obstacleGrid[i].size() ; j++){
                if(i == 0 && j != 0){
                    if(obstacleGrid[i][j] == 1)
                        dp_mat[i][j] = 0;
                    else
                        dp_mat[i][j] = dp_mat[i][j-1];
                }
                else if(i != 0 && j == 0){
                    if(obstacleGrid[i][j] == 1)
                        dp_mat[i][j] = 0;
                    else
                        dp_mat[i][j] = dp_mat[i-1][j];
                }
                else if(i == 0 && j == 0){
                    if(obstacleGrid[i][j] == 1)
                        dp_mat[i][j] = 0;
                    else
                        dp_mat[0][0] = 1;
                }
                else{
                    if(obstacleGrid[i][j] == 1)
                        dp_mat[i][j] = 0;
                    else
                        dp_mat[i][j] = dp_mat[i-1][j] + dp_mat[i][j-1];
                }
            }
        }
        
        return dp_mat[m-1][n-1];
    }
};