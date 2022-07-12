class Solution {
public:
    
    int BFS(vector<vector<int>>& grid){
        int ans = 0;
        
        int row_len = grid.size();
        int col_len = grid[0].size();
        
        for(int i = 0 ; i < row_len ; i++){
            for(int j = 0 ; j < col_len ; j++){
                
                if(grid[i][j] == 1){
                    int cur_max = 1;
                    grid[i][j] = 2;
                    queue<pair<int,int>> gq;
                    gq.push(make_pair(i, j));

                    while(!gq.empty()){
                        vector<pair<int,int>> gvec;
                        while(!gq.empty()){
                            gvec.push_back(gq.front());
                            gq.pop();
                        }
                        

                        for(int a = 0 ; a < gvec.size() ; a++){
                            int cur_x = gvec[a].first;
                            int cur_y = gvec[a].second;
                            if(cur_x - 1 >= 0 && grid[cur_x - 1][cur_y] == 1){
                                cur_max++;
                                grid[cur_x-1][cur_y] = 2;
                                gq.push(make_pair(cur_x-1, cur_y));
                            }
                            if(cur_x + 1 < row_len && grid[cur_x + 1][cur_y] == 1){
                                cur_max++;
                                grid[cur_x + 1][cur_y] = 2;
                                gq.push(make_pair(cur_x + 1, cur_y));
                            }
                            if(cur_y - 1 >= 0 && grid[cur_x][cur_y - 1] == 1){
                                cur_max++;
                                grid[cur_x][cur_y - 1] = 2;
                                gq.push(make_pair(cur_x, cur_y - 1));
                            }
                            if(cur_y + 1 < col_len && grid[cur_x][cur_y + 1] == 1){
                                cur_max++;
                                grid[cur_x][cur_y + 1] = 2;
                                gq.push(make_pair(cur_x, cur_y + 1));
                            }
                        }
                    }
                    cout << i << " " << j << " " << cur_max << endl;
                    ans = max(ans, cur_max);
                        
                    
                }
            }
        }
            
        return ans;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return BFS(grid);
    }
};