class Solution {
    
    Map<Integer, Integer> dict = new TreeMap<Integer,Integer>();
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void recur(int[] candidates, int target, ArrayList<Integer> cur_list, int cur_idx){
        
        if(cur_idx < 0){
            if(target == 0){
                ArrayList<Integer> tmp = new ArrayList<Integer>(cur_list);
                ans.add(tmp);
            }    
            return;
        }
        
        
        recur(candidates, target, cur_list, cur_idx - 1);
        
        if(dict.get(candidates[cur_idx]) > 0 && target - candidates[cur_idx] >= 0){
            
            cur_list.add(candidates[cur_idx]);
            int old_val = dict.get(candidates[cur_idx]);
            dict.replace(candidates[cur_idx], old_val - 1);
            recur(candidates, target - candidates[cur_idx], cur_list, cur_idx);
            old_val = dict.get(candidates[cur_idx]);
            dict.replace(candidates[cur_idx], old_val + 1);
            cur_list.remove(cur_list.size() - 1);
            
        }
        
        return;
        
    }
    
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        
        for(int i = 0 ; i < candidates.length ; i++){
            if(dict.containsKey(candidates[i])){
                int old_val = dict.get(candidates[i]);
                dict.replace(candidates[i], old_val + 1);
            }
            else
                dict.put(candidates[i], 1);
        }
        
        int[] new_candidates = new int[dict.size()];
        
        int i = 0;
        for(Map.Entry<Integer,Integer> entry_now : dict.entrySet()){
            new_candidates[i] = entry_now.getKey();
            i++;
        }
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        recur(new_candidates, target, start, new_candidates.length - 1);
        
        
        return ans;
    }
}