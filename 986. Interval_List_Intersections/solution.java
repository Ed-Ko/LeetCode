class Solution {
    public int[][] intervalIntersection(int[][] firstList, int[][] secondList) {
        
        int idx1 = 0;
        int idx2 = 0;
        
        Listint[] ans = new ArrayList();
        
        while(idx1  firstList.length && idx2  secondList.length){
            if(!(firstList[idx1][1]  secondList[idx2][0]  firstList[idx1][0]  secondList[idx2][1])){
                int start = Math.max(firstList[idx1][0], secondList[idx2][0]);
                int end = Math.min(firstList[idx1][1], secondList[idx2][1]);
                
                int[] tmp =  new int[]{start, end};
                ans.add(tmp);
                
            }
            
            if(firstList[idx1][1]  secondList[idx2][1])
                idx1++;
            else
                idx2++;
        }
        
        return ans.toArray(new int[ans.size()][]);
        
    }
}