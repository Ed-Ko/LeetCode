class Solution {
    public int[] twoSum(int[] nums, int target) {
        int idx1 = 0;
        int idx2 = 0;
        
        Map<Integer, Integer> dict = new HashMap<Integer, Integer>();
        
        for(int i = 0 ; i < nums.length ; i++){
            if(dict.containsKey(target - nums[i])){
                idx2 = i;
                idx1 = dict.get(target - nums[i]);
                break;
            }
            dict.put(nums[i], i);
        }
        
        return new int[]{idx1, idx2};
        
    }
}