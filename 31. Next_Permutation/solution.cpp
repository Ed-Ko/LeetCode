class Solution {
public:
    
    vector<int> recur(int cur_idx, vector<int>& cur_num){
        
        if(cur_idx == cur_num.size() - 1){
            vector<int> tmp;
            for(int i = cur_num.size() - 1 ; i >= 0 ; i--)
                tmp.push_back(cur_num[i]);
            return tmp;
        }
        
        
        if(cur_idx + 1 < cur_num.size()){
            if(cur_num[cur_idx] >= cur_num[cur_idx + 1])
                return recur(cur_idx + 1, cur_num);
            else{
                bool sub_sorted = 1;
                int sub_min = cur_idx + 1;
                for(int i = cur_idx + 1 ; i < cur_num.size() ; i++){
                    if(cur_num[sub_min] > cur_num[i] && cur_num[i] > cur_num[cur_idx])
                        sub_min = i;
                    
                    if(i + 1 < cur_num.size() && cur_num[i] < cur_num[i + 1]){
                        sub_sorted = false;
                        break;
                    }
                }
                if(sub_sorted){
                    int tmp = cur_num[sub_min];
                    cur_num[sub_min] = cur_num[cur_idx];
                    cur_num[cur_idx] = tmp;
                    sort(cur_num.begin() + cur_idx + 1, cur_num.end());
                    return cur_num;
                }
                else
                    return recur(cur_idx + 1, cur_num);
                
            }
        }
       
        vector<int> empty_vec;
        return empty_vec;
        
        
    }
    
    void nextPermutation(vector<int>& nums) {
        nums = recur(0, nums);
        return;
        
    }
};