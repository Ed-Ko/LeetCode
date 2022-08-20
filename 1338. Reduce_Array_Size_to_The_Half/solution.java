class Solution {
    public int minSetSize(int[] arr) {
        
        Map<Integer, Integer> dict = new HashMap<Integer, Integer>();
        int ans = 0;
        
        for(int i = 0 ; i < arr.length ; i++){
            if(dict.containsKey(arr[i])){
                int old_val = dict.get(arr[i]);
                dict.put(arr[i], old_val + 1);
            }
            else{
                dict.put(arr[i], 1);
            }
                
        }
        
        ArrayList<Integer> list = new ArrayList<Integer>();
        
        for(Map.Entry<Integer,Integer> set : dict.entrySet())
            list.add(set.getValue());
        
        Collections.sort(list);
        
        int counter = 0;
        for(int i = list.size() - 1 ; i >= 0 && counter < arr.length / 2 ; i--){
            //System.out.println(list.get(i));
            counter += list.get(i);
            ans++;
        }
        
        return ans;
        
        
    }
}