class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void recur(int[] candidates, int target, ArrayList<Integer> cur_list, int cur_idx){

        if(target == 0){
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur_list);
            ans.add(tmp);
            return;
        }    
        
        for(int i = cur_idx ; i < candidates.length ; i++){
            
            if(i > cur_idx && candidates[i] == candidates[i - 1])
                continue;
            
            if(target - candidates[i] < 0)
                break;
            
            cur_list.add(candidates[i]);
            
            recur(candidates, target - candidates[i], cur_list, i + 1);
            
            cur_list.remove(cur_list.size() - 1);
        }
        
        return;
        
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        Arrays.sort(candidates);
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        recur(candidates, target, start, 0);
        
        return ans;
    }
}