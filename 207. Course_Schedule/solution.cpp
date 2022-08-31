class Solution {
    
    Map<Integer,ArrayList<Integer>> path = new HashMap<Integer, List<Integer>>();
    
    int DFS(int cur_sub, int[] visited){
        
        int check = 1;
        
        visited[cur_sub] = 1;
        
        for(int i = 0 ; i < path[cur_sub].size() ; i++){
            if(visited[path[cur_sub][i]] == 1){
                check = 0;
                break;
            }
            else if(visited[path[cur_sub][i]] == 0){
                if(DFS(path[cur_sub][i], visited) == 1){
                    check = 0;
                    break;
                }
            }
                
        }
        
        if(check)
            visited[cur_sub] = 2;
        else
            visited[cur_sub] = 1;
        
        return visited[cur_sub];
        
    }
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
    }
}