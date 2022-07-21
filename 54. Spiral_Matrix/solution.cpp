class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int left_bound = 0;
        int right_bound = matrix[0].size() - 1;
        int up_bound = 1;
        int low_bound = matrix.size() - 1;
        
        int row_idx = 0;
        int col_idx = 0;
        vector<int> ans;
        
        int dir = 0;
        int ele_count = 0;
        int total_ele = matrix[0].size() * matrix.size();
        while(ele_count < total_ele){
            
            switch(dir){
                case 0:
                    ans.push_back(matrix[row_idx][col_idx]);
                    if(col_idx + 1 > right_bound){
                        dir = 1;
                        right_bound--;
                        row_idx++;
                    }
                    else
                        col_idx++;
                    break;
                case 1:
                    ans.push_back(matrix[row_idx][col_idx]);
                    if(row_idx + 1 > low_bound){
                        dir = 2;
                        low_bound--;
                        col_idx--;
                    }
                    else
                        row_idx++;
                    
                    break;
                case 2:
                    ans.push_back(matrix[row_idx][col_idx]);
                    if(col_idx - 1 < left_bound){
                        dir = 3;
                        left_bound++;
                        row_idx--;
                    }
                        
                    else
                        col_idx--;
                    break;
                case 3:
                    ans.push_back(matrix[row_idx][col_idx]);
                    if(row_idx - 1 < up_bound){
                        dir = 0;
                        up_bound++;
                        col_idx++;
                    }
                    else
                        row_idx--;
                    
                    break;
                    
                    
            }
            
            ele_count++;
        }
        return ans;
    }
};