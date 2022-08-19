class Solution {
public:
    
    vector<vector<int>> ans;
    
    void DFS(vector<vector<int>>& graph, int cur_val, vector<int>& cur_vec){
        
        cur_vec.push_back(cur_val);
        
        if(cur_val == graph.size() - 1){
            ans.push_back(cur_vec);
            cur_vec.pop_back();
            return;
        }
        
        for(int i = 0 ; i < graph[cur_val].size() ; i++){
            DFS(graph, graph[cur_val][i], cur_vec);
        }
        
        cur_vec.pop_back();
        
        return;
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<int> start;
        
        DFS(graph, 0, start);
        
        return ans;
        
    }
};