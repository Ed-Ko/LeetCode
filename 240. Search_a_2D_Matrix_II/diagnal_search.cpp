class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int cur_col = matrix[0].size() - 1;
        
        for(int i = 0 ; i < matrix.size() ; i++){
            while(cur_col >= 0 && matrix[i][cur_col] > target)
                cur_col--;
            if(cur_col < 0)
                return false;
            if(matrix[i][cur_col] == target)
                return true;
        }
        
        return false;
        
    }
};