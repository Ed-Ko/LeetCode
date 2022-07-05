class Solution {
public:
    
    bool path_exist = false;
    int length = 0;
    
    
    void BFS(vector<vector<int>>& grid, int x_in, int y_in){
        
        queue<pair<int,int>> pos_queue;
        vector<vector<bool>> visited;
        pos_queue.push(make_pair(0,0));
        visited.resize(grid.size(), vector<bool>(grid.size()));
        visited[0][0] = true;
        
        if(x_in == grid.size() - 1 && y_in == grid.size() - 1 && grid[x_in][y_in] == 0)
            path_exist = true;
            
        
        while(!pos_queue.empty()){
            
            length++;
            
            vector<pair<int,int>> pos_vec;
            while(!pos_queue.empty()){
                pos_vec.push_back(pos_queue.front());
                pos_queue.pop();
            }
            
            for(int i = 0 ; i < pos_vec.size() ; i++){
                int x_now = pos_vec[i].first;
                int y_now = pos_vec[i].second;
                
                if(x_now == grid.size() - 1 && y_now == grid.size() - 1){
                    path_exist = true;
                    return;
                }
                
                if(x_now + 1 < grid.size() && y_now + 1 < grid.size() && grid[x_now + 1][y_now + 1] == 0 && !path_exist && !visited[x_now + 1][y_now + 1]){
                    pos_queue.push(make_pair(x_now + 1, y_now + 1));
                    visited[x_now + 1][y_now + 1] = true;
                }
            
                if(x_now + 1 < grid.size() && grid[x_now + 1][y_now] == 0 && !path_exist && !visited[x_now + 1][y_now]){
                    pos_queue.push(make_pair(x_now + 1, y_now));
                    visited[x_now + 1][y_now] = true;
                }

                if(y_now + 1 < grid.size() && grid[x_now][y_now + 1] == 0 && !path_exist && !visited[x_now][y_now + 1]){
                    pos_queue.push(make_pair(x_now, y_now + 1));
                    visited[x_now][y_now + 1] = true;
                }


                if(x_now + 1 < grid.size() && y_now - 1 >= 0 && grid[x_now + 1][y_now - 1] == 0 && !path_exist && !visited[x_now + 1][y_now - 1]){
                    pos_queue.push(make_pair(x_now + 1, y_now - 1));
                    visited[x_now + 1][y_now - 1] = true;
                }

                if(x_now - 1 >= 0 && y_now + 1 < grid.size() && grid[x_now - 1][y_now + 1] == 0 && !path_exist && !visited[x_now - 1][y_now + 1]){
                    pos_queue.push(make_pair(x_now - 1, y_now + 1));
                    visited[x_now - 1][y_now + 1] = true;
                }


                if(x_now - 1 >= 0 && grid[x_now - 1][y_now] == 0 && !path_exist && !visited[x_now - 1][y_now]){
                    pos_queue.push(make_pair(x_now - 1, y_now));
                    visited[x_now - 1][y_now] = true;
                }
                    

                if(y_now - 1 >= 0 && grid[x_now][y_now - 1] == 0 && !path_exist && !visited[x_now][y_now - 1]){
                    pos_queue.push(make_pair(x_now, y_now - 1));
                    visited[x_now][y_now - 1] = true;
                }


                if(x_now - 1 >= 0 && y_now - 1 >= 0 && grid[x_now - 1][y_now - 1] == 0 && !path_exist && !visited[x_now - 1][y_now - 1]){
                    pos_queue.push(make_pair(x_now - 1, y_now - 1));
                    visited[x_now - 1][y_now - 1] = true;
                }
            }
            
            
        }
        
        return;
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        
        if(grid[0][0] != 1){
            BFS(grid, 0, 0);
        }
        
        if(path_exist == true)
            return length;
        return -1;
    }
};