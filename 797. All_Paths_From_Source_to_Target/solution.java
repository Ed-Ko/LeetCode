class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void DFS(int[][] graph, int cur_val, ArrayList<Integer> cur_vec){
        
        cur_vec.add(cur_val);
        
        if(cur_val == graph.length - 1){
            ArrayList<Integer> tmp = new ArrayList<Integer>();
            tmp.addAll(0, cur_vec);
            ans.add(tmp);
            cur_vec.remove(cur_vec.size() - 1);
            return;
        }
        
        for(int i = 0 ; i < graph[cur_val].length ; i++)
            DFS(graph, graph[cur_val][i], cur_vec);
        
        cur_vec.remove(cur_vec.size() - 1);
        
        return;
    }
    
    
    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        
        DFS(graph, 0, start);
            
        return ans;
    }
}