class Solution {
public:
    
    int recur(vector<vector<int>>& triangle, int layer_num, int cur_idx){
        
        if(layer_num >= triangle.size() - 1)
            return triangle[layer_num][cur_idx];
        
        
        int left_idx = cur_idx;

        int right_idx;
        if(cur_idx + 1 <= triangle[layer_num + 1].size() - 1)
            right_idx = cur_idx + 1;
        else
            right_idx = triangle[layer_num + 1].size() - 1;

        int left_len = recur(triangle, layer_num + 1, left_idx);
        int right_len = recur(triangle, layer_num + 1, right_idx);
       
        return min(left_len, right_len) + triangle[layer_num][cur_idx];
        
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        return recur(triangle, 0, 0);
        
    }
};