class Solution {
public:
    
    void DFS(vector<vector<char>>& board, vector<vector<int>>& visited, int cur_x, int cur_y){
        
        if(cur_x < 0 || cur_x >= board.size() || cur_y < 0 || cur_y >= board[0].size())
            return;
        
        if(board[cur_x][cur_y] == 'O' && !visited[cur_x][cur_y]){
            visited[cur_x][cur_y] = 1;
            board[cur_x][cur_y] = 'S';

            DFS(board, visited, cur_x - 1, cur_y);    
            DFS(board, visited, cur_x + 1, cur_y); 
            DFS(board, visited, cur_x, cur_y - 1); 
            DFS(board, visited, cur_x, cur_y + 1); 
        }
        
        
        return;
        
    }
    
    void solve(vector<vector<char>>& board) {
        
        vector<vector<int>> visited(board.size(), vector<int>(board[0].size(), 0));
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                if(!visited[i][j] && board[i][j] == 'O' && (i == 0 || j == 0 || i == board.size() - 1 || j == board[0].size() - 1)){
                    DFS(board, visited, i, j);
                }
            }
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