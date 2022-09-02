class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        
        ArrayList<Integer> ans = new ArrayList<Integer>();
        
        int[] dict = new int[1001];
        Arrays.fill(dict, 0);
        
        for(int i = 0 ; i < nums1.length ; i++)
            dict[nums1[i]]++;
        
        for(int i = 0 ; i < nums2.length ; i++){
            if(dict[nums2[i]] > 0){
                dict[nums2[i]]--;
                ans.add(nums2[i]);
            }
        }
        
        int[] final_ans = new int[ans.size()];
        for(int i = 0 ; i < ans.size() ; i++)
            final_ans[i] = ans.get(i);
        return final_ans;
        
    }
}