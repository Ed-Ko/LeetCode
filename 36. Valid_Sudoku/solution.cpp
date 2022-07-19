class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int vertical[9][10];
        int horizon[9][10];
        int sq[9][10];
        
        memset(vertical, 0, sizeof(vertical));
        memset(horizon, 0, sizeof(horizon));
        memset(sq, 0, sizeof(sq));
        
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                //cout << " ===" << board[i][j] << "=== " << endl;
                if(board[i][j] != '.'){
                    if(horizon[i][board[i][j] - '0'] == 0)
                        horizon[i][board[i][j] - '0'] = 1;
                    else
                        return false;
                    if(vertical[j][board[i][j] - '0'] == 0)
                        vertical[j][board[i][j] - '0'] = 1;
                    else
                        return false;
                    if(sq[((i / 3) * 3 + (j / 3))][board[i][j] - '0'] == 0)
                        sq[((i / 3) * 3 + (j / 3))][board[i][j] - '0'] = 1;
                    else
                        return false;
                }
                
            }
        }
        
        return true;
                                  
    }
};