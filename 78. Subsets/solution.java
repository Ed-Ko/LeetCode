class Solution {
    
    List<List<Integer>> ans = new ArrayList<List<Integer>>();
    
    public void recur(int[] nums, ArrayList<Integer> cur_vec, int depth, int idx){
        
        cur_vec.add(nums[idx]);
        
        if(depth == 0){
            ArrayList<Integer> tmp = new ArrayList<Integer>(cur_vec);
            ans.add(tmp);
            cur_vec.remove(cur_vec.size() - 1);
            return;
        }
        
        for(int i = idx + 1 ; i < nums.length - depth + 1 ; i++)
            recur(nums, cur_vec, depth - 1, i);
        
        cur_vec.remove(cur_vec.size() - 1);
        
        return;
        
    }
    
    
    public List<List<Integer>> subsets(int[] nums) {
        
        ans.add(new ArrayList<Integer>());
        
        for(int i = 1 ; i <= nums.length ; i++){
            for(int j = 0 ; j < nums.length ; j++){
                recur(nums, new ArrayList<Integer>(), i - 1, j);
            }
        }
        
        return ans;
        
    }
}