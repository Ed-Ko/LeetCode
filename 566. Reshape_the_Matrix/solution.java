class Solution {
    public int[][] matrixReshape(int[][] mat, int r, int c) {
        
        int row_num = mat.length;
        int col_num = mat[0].length;
        
        if(r * c > row_num * col_num || r * c < row_num * col_num)
            return mat;
        
        int[][] new_mat = new int[r][c];
        
        for(int i = 0 ; i < row_num ; i++){
            for(int j = 0 ; j < col_num ; j++){
                int new_pos = i * col_num + j;
                new_mat[new_pos / c][new_pos % c] = mat[i][j];
            }
        }
        
        return new_mat;
        
    }
}