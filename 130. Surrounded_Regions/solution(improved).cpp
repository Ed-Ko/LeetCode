class Solution {
public:
    
    void DFS(vector<vector<char>>& board, int cur_x, int cur_y){
        
        if(cur_x < 0 || cur_x >= board.size() || cur_y < 0 || cur_y >= board[0].size())
            return;
        
        if(board[cur_x][cur_y] == 'O'){
            board[cur_x][cur_y] = 'S';

            DFS(board, cur_x - 1, cur_y);    
            DFS(board, cur_x + 1, cur_y); 
            DFS(board, cur_x, cur_y - 1); 
            DFS(board, cur_x, cur_y + 1); 
        }
        
        
        return;
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0 ; i < board.size() ; i++){
            if(board[i][0] == 'O')
                DFS(board, i, 0);
            if(board[i][board[0].size() - 1] == 'O')
                DFS(board, i, board[0].size() - 1);
        }
        
        for(int i = 0 ; i < board[0].size() ; i++){
            if(board[0][i] == 'O')
                DFS(board, 0, i);
            if(board[board.size() - 1][i] == 'O')
               DFS(board, board.size() - 1, i);
        }
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(board[i][j] == 'S')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
                
            }
        }
        
        return;
        
    }
};