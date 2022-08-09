class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        vector<vector<int>> ans;
        ans.resize(board.size(), vector<int>(board[0].size()));
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                
                if(board[i][j] == 1){
                    int live = 0;
                    if(i - 1 >= 0 && board[i - 1][j] == 1)
                        live++;
                    if(i + 1 < board.size() && board[i + 1][j] == 1)
                        live++;
                    if(j - 1 >= 0 && board[i][j - 1] == 1)
                        live++;
                    if(j + 1 < board[0].size() && board[i][j + 1] == 1)
                        live++;

                    if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
                        live++;
                    if(i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 1)
                        live++;
                    if(i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 1)
                        live++;
                    if(i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 1)
                        live++;
                    
                    if(2 <= live && live <= 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                    
                }

                else{
                    int live = 0;
                    if(i - 1 >= 0 && board[i - 1][j] == 1)
                        live++;
                    if(i + 1 < board.size() && board[i + 1][j] == 1)
                        live++;
                    if(j - 1 >= 0 && board[i][j - 1] == 1)
                        live++;
                    if(j + 1 < board[0].size() && board[i][j + 1] == 1)
                        live++;
                    
                    if(i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 1)
                        live++;
                    if(i + 1 < board.size() && j + 1 < board[0].size() && board[i + 1][j + 1] == 1)
                        live++;
                    if(i + 1 < board.size() && j - 1 >= 0 && board[i + 1][j - 1] == 1)
                        live++;
                    if(i - 1 >= 0 && j + 1 < board[0].size() && board[i - 1][j + 1] == 1)
                        live++;
                    
                    if(live == 3)
                        ans[i][j] = 1;
                    else
                        ans[i][j] = 0;
                }
                
                
                
            }
        }
        
        
        board = ans;
        
        return;
    }
};