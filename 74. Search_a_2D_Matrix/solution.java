class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        
        int left = 0;
        int right = matrix.length * matrix[0].length - 1;
        
        while(left <= right){
            
            int mid = (left + right) / 2;
            
            int mid_num = matrix[mid / matrix[0].length][mid % matrix[0].length];
            
            if(mid_num == target)
                return true;
            else if(mid_num < target)
                left = mid + 1;
            else
                right = mid - 1;
            
        }
        
        return false;
        
    }
}