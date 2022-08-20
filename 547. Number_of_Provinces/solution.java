class Solution {
    
    public void DFS(int[][] isConnected, int cur_idx, boolean[] visited){
        
        for(int i = 0 ; i < isConnected.length ; i++){
            if(i != cur_idx && !visited[i] && isConnected[cur_idx][i] == 1){
                visited[i] = true;
                DFS(isConnected, i, visited);
            }
        }
        
        return;
        
    }
    
    
    public int findCircleNum(int[][] isConnected) {
        
        boolean[] visited = new boolean[isConnected.length];
        
        int ans = 0;
        
        for(int i = 0 ; i < isConnected.length ; i++){
            if(!visited[i]){
                visited[i] = true;
                DFS(isConnected, i, visited);
                ans++;
            }    
        }
        
        return ans;
        
    }
}