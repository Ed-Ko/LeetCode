class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        int ma[31][31];
        memset(ma, 0, sizeof(ma));
        vector<vector<int>> dict;
        
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
            vector<int> cur_vec;
            for(int j = 0 ; j < numRows ; j++){
                if(ma[i][j] != 0)
                    cur_vec.push_back(ma[i][j]);
            }
            dict.push_back(cur_vec);
        }
        
        return dict;
    }
};