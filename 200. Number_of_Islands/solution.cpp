class Solution {
public:
    
    int BFS(vector<vector<char>>& grid){
        
        int island_num = 0;
        int row_num = grid.size();
        int col_num = grid[0].size();
        int visited[300][300];
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0 ; i < row_num ; i++){
            for(int j = 0 ; j < col_num ; j++){
                
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    //cout << " ===== " << endl;
                    island_num++;
                    queue<pair<int,int>> pos_q;
                    vector<pair<int,int>> pos_vec;
                    pos_q.push(make_pair(i,j));
                    
                    while(!pos_q.empty()){
                        while(!pos_q.empty()){
                            pos_vec.push_back(pos_q.front());
                            pos_q.pop();
                        }
                        for(int k = 0 ; k < pos_vec.size() ; k++){
                            int cur_row = pos_vec[k].first;
                            int cur_col = pos_vec[k].second;
                            if(cur_row - 1 >= 0 && visited[cur_row - 1][cur_col] == 0 && grid[cur_row - 1][cur_col] == '1'){
                                visited[cur_row - 1][cur_col] = 1;
                                pos_q.push(make_pair(cur_row - 1, cur_col));
                            }
                            if(cur_row + 1 < grid.size() && visited[cur_row + 1][cur_col] == 0 && grid[cur_row + 1][cur_col] == '1'){
                                visited[cur_row + 1][cur_col] = 1;
                                pos_q.push(make_pair(cur_row + 1, cur_col));
                            }
                            if(cur_col - 1 >= 0 && visited[cur_row][cur_col - 1] == 0 && grid[cur_row][cur_col - 1] == '1'){
                                visited[cur_row][cur_col - 1] = 1;
                                pos_q.push(make_pair(cur_row, cur_col - 1));
                            }
                            if(cur_col + 1 < grid[0].size() && visited[cur_row][cur_col + 1] == 0 && grid[cur_row][cur_col + 1] == '1'){
                                visited[cur_row][cur_col + 1] = 1;
                                pos_q.push(make_pair(cur_row, cur_col + 1));
                            }
                        }
                        
                        
                    }
                    
                }
                
                
            }
        }
        
        
        
        return island_num;

    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        return BFS(grid);
        
    }
};