class Solution {
public:
    
    bool BFS(vector<vector<int>>& matrix, int target){
        
        queue<pair<int,int>> q;
        q.push(make_pair(0,0));
        int visited[300][300];
        memset(visited, 0, sizeof(visited));
        
        while(!q.empty()){
            
            vector<pair<int,int>> pos_vec;
            
            while(!q.empty()){
                pos_vec.push_back(q.front());
                q.pop();
            }
            
            for(int i = 0 ; i < pos_vec.size() ; i++){
                int cur_row = pos_vec[i].first;
                int cur_col = pos_vec[i].second;
                
                if(matrix[cur_row][cur_col] == target)
                    return true;
                    
                visited[cur_row][cur_col] = 1;
                if(cur_row + 1 < matrix.size() && matrix[cur_row + 1][cur_col] <= target && !visited[cur_row + 1][cur_col])
                    q.push(make_pair(cur_row + 1, cur_col));
                if(cur_col + 1 < matrix[0].size() && matrix[cur_row][cur_col + 1] <= target && !visited[cur_row][cur_col + 1])
                    q.push(make_pair(cur_row, cur_col + 1));
                
            }
            
            
            
        }
       
        return false;
        
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        return BFS(matrix, target);
        
    }
};