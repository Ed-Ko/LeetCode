class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void recur(int[] candidates, int target, ArrayList<Integer> cur_vec, int idx){
        
        if(target == 0){
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur_vec);
            ans.add(tmp);
            return;
        }
        
        int i = idx;
        
        
        while(i < candidates.length && (target - candidates[i]) >= 0){
            
            cur_vec.add(candidates[i]);
            recur(candidates, target - candidates[i], cur_vec, i);
            i++;
            cur_vec.remove(cur_vec.size() - 1);
            
        }
        
        return;
        
    }
    
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        
        Set<Integer> tmp_set = new TreeSet<Integer>();
        
        for(int i = 0 ; i < candidates.length ; i++)
            tmp_set.add(candidates[i]);

        
        int[] new_candidates = new int[tmp_set.size()];
        
        int i = 0;
        for(Integer cur_val : tmp_set){
            new_candidates[i] = cur_val;
            i++;
        }
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        
        recur(new_candidates, target, start, 0);
        
        return ans;
        
    }
}