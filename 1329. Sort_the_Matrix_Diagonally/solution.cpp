class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int cur_row = mat.size() - 1;
        int cur_col = 0;
        
        while(cur_row >= 0 && cur_col < mat[0].size()){
            
            vector<int> cur_vec;
            
            for(int i = cur_row, j = cur_col ; i < mat.size() && j < mat[0].size() ; i++, j++)
                cur_vec.push_back(mat[i][j]);
                
            sort(cur_vec.begin(), cur_vec.end());
            
            int k = 0;
            for(int i = cur_row, j = cur_col ; i < mat.size() && j < mat[0].size() ; i++, j++){
                mat[i][j] = cur_vec[k];
                k++;
            }
            
            if(cur_row > 0)
                cur_row--;
            else
                cur_col++;
                
        }
        
        return mat;
        
    }
};