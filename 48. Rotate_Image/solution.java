class Solution {
    public void rotate(int[][] matrix) {
        
        int round = (matrix.length + 1) / 2;
        
        for(int i = 1 ; i <= round ; i++){
            
            int[] top_left = new int[]{i - 1, i - 1};
            int[] top_right = new int[]{i - 1, matrix[0].length - i};
            int[] down_left = new int[]{matrix.length - i, i - 1};
            int[] down_right = new int[]{matrix.length - i, matrix[0].length - i};
            
            int buf;
            
            for(int j = i - 1 ; j < matrix[0].length - i ; j++){
                
                buf = matrix[top_left[0]][top_left[1]];
                
                matrix[top_left[0]][top_left[1]] = matrix[down_left[0]][down_left[1]];
                matrix[down_left[0]][down_left[1]] = matrix[down_right[0]][down_right[1]];
                matrix[down_right[0]][down_right[1]] = matrix[top_right[0]][top_right[1]];
                matrix[top_right[0]][top_right[1]] = buf;
                
                top_left[1]++;
                top_right[0]++;
                down_right[1]--;
                down_left[0]--;
                
            }
            
            
        }
        
        return;
        
        
        
    }
}