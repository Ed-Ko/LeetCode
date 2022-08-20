class Solution {
public:
    
    int ans = 0;
    
    void DFS(vector<vector<int>>& isConnected, int cur_idx, vector<int>& visited){
        
        for(int i = 0 ; i < isConnected[cur_idx].size() ; i++){
            if(isConnected[cur_idx][i] == 1 && !visited[i]){
                visited[i] = 1;
                DFS(isConnected, i, visited);
            }
                
        }
        
        return;
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
       
        vector<int> visited(isConnected.size(), 0);
        
        for(int i = 0 ; i < isConnected.size() ; i++){
            if(!visited[i]){
                visited[i] = 1;
                DFS(isConnected, i, visited);
                ans++;
            }
        }
        
        
        return ans;
    }
};