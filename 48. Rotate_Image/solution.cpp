class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int round = (matrix.size() + 1) / 2;
        
        for(int i = 1 ; i <= round ; i++){
            
            pair<int,int> top_left(i - 1, i - 1);
            pair<int,int> top_right(i - 1, matrix[0].size() - i);
            pair<int,int> down_left(matrix.size() - i, i - 1);
            pair<int,int> down_right(matrix.size() - i, matrix[0].size() - i);
            
            int buf;
            
            for(int j = i - 1 ; j < matrix[0].size() - i ; j++){
                
                buf = matrix[top_left.first][top_left.second];
                
                matrix[top_left.first][top_left.second] = matrix[down_left.first][down_left.second];
                matrix[down_left.first][down_left.second] = matrix[down_right.first][down_right.second];
                matrix[down_right.first][down_right.second] = matrix[top_right.first][top_right.second];
                matrix[top_right.first][top_right.second] = buf;
                
                top_left.second++;
                top_right.first++;
                down_right.second--;
                down_left.first--;
                
            }
            
            
        }
        
        return;
        
    }
};