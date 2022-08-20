class Solution {
    
    public void DFS(char[][] grid, int[][] visited, int cur_x, int cur_y){
        
        visited[cur_x][cur_y] = 1;
        
        if(cur_x - 1 >= 0 && visited[cur_x - 1][cur_y] == 0 && grid[cur_x - 1][cur_y] == '1')
            DFS(grid, visited, cur_x - 1, cur_y);
        if(cur_x + 1 < grid.length && visited[cur_x + 1][cur_y] == 0 && grid[cur_x + 1][cur_y] == '1')
            DFS(grid, visited, cur_x + 1, cur_y);
        if(cur_y - 1 >= 0 && visited[cur_x][cur_y - 1] == 0 && grid[cur_x][cur_y - 1] == '1')
            DFS(grid, visited, cur_x, cur_y - 1);
        if(cur_y + 1 < grid[0].length && visited[cur_x][cur_y + 1] == 0 && grid[cur_x][cur_y + 1] == '1')
            DFS(grid, visited, cur_x, cur_y + 1);
        
        return;
    }
    
    
    public int numIslands(char[][] grid) {
        
        int[][] visited = new int[grid.length][grid[0].length];
        
        int ans = 0;
        
        for(int i = 0 ; i < grid.length ; i++){
            for(int j = 0 ; j < grid[0].length ; j++){
                if(visited[i][j] == 0 && grid[i][j] == '1'){
                    DFS(grid, visited, i, j);
                    ans++;
                }
                    
            }
        }
        
        return ans;
        
    }
}