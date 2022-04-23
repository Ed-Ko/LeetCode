class Solution {
public:
    int integerReplacement(int n) {
        
        int ans;
        unordered_map<int ,int> dp_map;
        vector<vector<int>> dp_vec;
        
        vector<int> tmp;
        tmp.insert(tmp.end(), {n,0});
        dp_vec.push_back(tmp);
        dp_map[n] = 0;
        
        if(n == 1)
            return 0;
        
        for(int i = 0 ; i < dp_vec.size() ; i++){
            
            int cur_val = dp_vec[i][0];
            int cur_step = dp_vec[i][1];
            cout << cur_step << " " << cur_val << endl;
            
            
            if(cur_val % 2 == 1){
                int val1;
                if(cur_val < INT_MAX)
                    val1 = cur_val + 1;
                else
                    val1 = (cur_val / 2) + 1;
                int val2 = cur_val - 1;
                
                if((val1 == 1 && val1 > 0) || (val2 == 1 && val2 > 0)){
                    ans = cur_step + 1;
                    break;
                }
                else{
                    if(cur_val == INT_MAX && dp_map.find(val1) == dp_map.end()){
                        dp_map[val1] = cur_step + 2;
                        vector<int> tmp;
                        tmp.insert(tmp.end(), {(cur_val / 2) + 1, cur_step + 2});
                        dp_vec.push_back(tmp);
                    }
                    if(dp_map.find(val1) == dp_map.end()){
                        dp_map[val1] = cur_step + 1;
                        vector<int> tmp;
                        tmp.insert(tmp.end(), {val1, cur_step + 1});
                        dp_vec.push_back(tmp);
                    }
                    if(dp_map.find(val2) == dp_map.end()){
                        dp_map[val2] = cur_step + 1;
                        vector<int> tmp;
                        tmp.insert(tmp.end(), {val2, cur_step + 1});
                        dp_vec.push_back(tmp);
                    }
                }

            }
            else{
                int val1 = cur_val / 2;
                
                if(val1 == 1){
                    ans = cur_step + 1;
                    break;
                }
                else{
                    if(dp_map.find(val1) == dp_map.end()){
                        dp_map[val1] = cur_step + 1;
                        vector<int> tmp;
                        tmp.insert(tmp.end(), {val1, cur_step + 1});
                        dp_vec.push_back(tmp);
                    }
                }
                
            }
            
        }
        
        return ans;
        
    }
};