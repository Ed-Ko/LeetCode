class Solution {
    public int[][] diagonalSort(int[][] mat) {
        
        
        int cur_row = mat.length - 1;
        int cur_col = 0;
        
        while(cur_row >= 0 && cur_col < mat[0].length){
            
            ArrayList<Integer> cur_vec = new ArrayList<Integer>();
            
            for(int i = cur_row, j = cur_col ; i < mat.length && j < mat[0].length ; i++, j++)
                cur_vec.add(mat[i][j]);
                
            Collections.sort(cur_vec);
            
            int k = 0;
            for(int i = cur_row, j = cur_col ; i < mat.length && j < mat[0].length ; i++, j++){
                mat[i][j] = cur_vec.get(k);
                k++;
            }
            
            if(cur_row > 0)
                cur_row--;
            else
                cur_col++;
                
        }
        
        return mat;
        
        
        
    }
}