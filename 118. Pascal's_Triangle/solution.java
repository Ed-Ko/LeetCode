class Solution {
    public List<List<Integer>> generate(int numRows) {
        
        int[][] ma = new int[31][31];
        List<List<Integer>> dict = new ArrayList<List<Integer>>();
        
        for(int i = 0 ; i <= numRows ; i++){
            
            if(i == 0){
                ma[i][0] = 1;
                continue;
            }
                
            if(i == 1){
                ma[i][0] = 1;
                ma[i][1] = 1;
                continue;
            }
            
            ma[i][0] = 1;
            for(int j = 1 ; j < numRows ; j++){
                int sum = 0;
                sum += ma[i - 1][j - 1];
                if(j < i)
                    sum += ma[i - 1][j];
                ma[i][j] = sum;
            }
            
        }
        
        for(int i = 0 ; i < numRows ; i++){
            ArrayList<Integer> cur_vec = new ArrayList<Integer>();
            for(int j = 0 ; j < numRows ; j++){
                if(ma[i][j] != 0)
                    cur_vec.add(ma[i][j]);
            }
            dict.add(cur_vec);
        }
        
        return dict;
        
        
    }
}