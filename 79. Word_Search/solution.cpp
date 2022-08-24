class Solution {
public:
    
    bool recur(vector<vector<char>>& board, string word, int idx, int x, int y, vector<vector<int>>& visited){
        
        if(board[x][y] != word[idx])
            return false;
        
        if(idx == word.length() - 1)
            return true;
        
        bool up = false;
        bool down = false;
        bool left = false;
        bool right = false;
        
        visited[x][y] = 1;
        
        if(x - 1 >= 0 && !visited[x - 1][y])
            up = recur(board, word, idx + 1, x - 1, y, visited);
            
        if(x + 1 < board.size() && !visited[x + 1][y])
            down = recur(board, word, idx + 1, x + 1, y, visited);
        
        if(y - 1 >= 0 && !visited[x][y - 1])
            left = recur(board, word, idx + 1, x, y - 1, visited);
        
        if(y + 1 < board[0].size() && !visited[x][y + 1])
            right = recur(board, word, idx + 1, x, y + 1, visited);
        
        visited[x][y] = 0;
        
        return up || down || left || right;
        
    }
    
    
    
    bool exist(vector<vector<char>>& board, string word) {
        
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(board[i][j] == word[0] && !visited[i][j] && recur(board, word, 0, i, j, visited))
                    return true;
            }
        }
        
        return false;
        
    }
};