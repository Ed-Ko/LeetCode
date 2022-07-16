class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        for(int i = 0 ; i < matrix.size() ; i++){
            if(matrix[i][0] == target)
                return true;
            
            if(i + 1 < matrix.size() && matrix[i + 1][0] < target)
                continue;
            
            for(int j = 0 ; j < matrix[0].size() ; j++){
                if(matrix[i][j] == target)
                    return true;
                if(j + 1 < matrix[0].size() && matrix[i][j] < target && target < matrix[i][j+1])
                    return false;
            }
        }
        return false;
        
    }
};