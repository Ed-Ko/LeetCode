class Solution {
public:
    
    map<int, vector<int>> graph;
    vector<vector<int>> ans;
    vector<int> min_time;
    vector<int> first_visit;
    vector<int> visited;
    int time = 1;
    
    void DFS(int cur_node, int parent = -1){
        
        min_time[cur_node] = time;
        first_visit[cur_node] = time;
        time++;
        visited[cur_node] = 1;
        
        for(int i = 0 ; i < graph[cur_node].size() ; i++){
            
            int child_now = graph[cur_node][i];
            
            if(child_now == parent)
                continue;
            
            if(!visited[child_now])
                DFS(child_now, cur_node);
            
            min_time[cur_node] = min(min_time[child_now], min_time[cur_node]);
            
            if(first_visit[cur_node] < min_time[child_now]){
                //cout << "in : " << cur_node << " " << child_now << endl;
                ans.push_back({cur_node, child_now});
            }
        }
        
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        min_time.resize(n);
        first_visit.resize(n);
        visited.resize(n);
        
        for(int i = 0 ; i < connections.size() ; i++){
            graph[connections[i][0]].push_back(connections[i][1]);
            graph[connections[i][1]].push_back(connections[i][0]);
        }
        
        DFS(0);
        return ans;
    }
    
};