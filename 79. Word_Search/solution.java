class Solution {
    
    public boolean recur(char[][] board, String word, int idx, int x, int y, int[][] visited){
        
        if(board[x][y] != word.charAt(idx))
            return false;
        
        if(idx == word.length() - 1)
            return true;
        
        boolean up = false;
        boolean down = false;
        boolean left = false;
        boolean right = false;
        
        visited[x][y] = 1;
        
        if(x - 1 >= 0 && visited[x - 1][y] == 0)
            up = recur(board, word, idx + 1, x - 1, y, visited);
        if(x + 1 < board.length && visited[x + 1][y] == 0)
            down = recur(board, word, idx + 1, x + 1, y, visited);
        if(y - 1 >= 0 && visited[x][y - 1] == 0)
            left = recur(board, word, idx + 1, x, y - 1, visited);
        if(y + 1 < board[0].length && visited[x][y + 1] == 0)
            right = recur(board, word, idx + 1, x, y + 1, visited);
        
        visited[x][y] = 0;
        
        return up || down || left || right; 
        
    }
    
    public boolean exist(char[][] board, String word) {
        
        int[][] visited = new int[board.length][board[0].length];
        
        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < board[0].length ; j++){
                if(board[i][j] == word.charAt(0) && visited[i][j] == 0 && recur(board, word, 0, i, j, visited))
                    return true;
            }
        }
        
        return false;
    }
}