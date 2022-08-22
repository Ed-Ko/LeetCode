class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    Map<Integer, Integer> dict = new TreeMap<Integer, Integer>();
    
    public void recur(int[] nums, ArrayList<Integer> cur_vec , int depth, int cur_val){
        
        cur_vec.add(cur_val);
        
        if(depth == 0){
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur_vec);
            ans.add(tmp);
            cur_vec.remove(cur_vec.size() - 1);
            return;
        }
        
        for(Map.Entry<Integer,Integer> entry_now : dict.entrySet()){
            
            int val_now = entry_now.getKey();
            
            if(val_now >= cur_val){
                if(dict.get(val_now) > 0){
                    int old_val = dict.get(val_now);
                    dict.replace(val_now, old_val - 1);
                    recur(nums, cur_vec, depth - 1, val_now);
                    old_val = dict.get(val_now);
                    dict.replace(val_now, old_val + 1);
                }
            }
            
        }
        
        cur_vec.remove(cur_vec.size() - 1);
        
        return;
    }
    
    
    
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        
        for(int i = 0 ; i < nums.length ; i++){
            if(dict.containsKey(nums[i])){
                int old_val = dict.get(nums[i]);
                dict.replace(nums[i], old_val + 1);
            }
            else
                dict.put(nums[i], 1);
        }
        
        ArrayList<Integer> start = new ArrayList<Integer>();
        ans.add(start);
        
        for(int i = 1 ; i <= nums.length ; i++){
            for(Integer j : dict.keySet()){
                int old_val = dict.get(j);
                dict.replace(j, old_val - 1);
                recur(nums, start, i - 1, j);
                old_val = dict.get(j);
                dict.replace(j, old_val + 1);
            }
        }
        
        
        return ans;
    }
}