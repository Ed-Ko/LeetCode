class Solution {
public:
    
    bool DFS(vector<vector<int>>& matrix, int target, int cur_row, int cur_col){
    
        if(matrix[cur_row][cur_col] == target)
            return true;
        
        bool left_return = false;
        bool right_return = false;
        if(cur_row + 1 < matrix.size())
            left_return =  DFS(matrix, target, cur_row + 1, cur_col);
        if(cur_col + 1 < matrix[0].size())
            right_return = DFS(matrix, target, cur_row, cur_col + 1);
        
        return (left_return || right_return);
        
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return DFS(matrix, target, 0, 0);
        
    }
};