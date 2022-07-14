class Solution {
public:
    
    vector<int> len_vec;
    bool ans = false;
    
    bool recur(int idx, int side_len, vector<int>& matchsticks){
        
        
        //for(int i = 0 ; i < 4 ; i++)
        //    cout << len_vec[i] << " ";
        //cout << endl;
        
        if(idx == matchsticks.size()){
            if(len_vec[0] == side_len && len_vec[1] == side_len && len_vec[2] == side_len && len_vec[3] == side_len)
                return true;
            else
                return false;
        }
        
        for(int i = 0 ; i < 4 ; i++){
            if(len_vec[i] + matchsticks[idx] <= side_len){
                
                len_vec[i] += matchsticks[idx];
                if(recur(idx + 1, side_len, matchsticks))
                    return true;
                len_vec[i] -= matchsticks[idx];
                
            }

        }
    
        return false;
        
    }
    
    bool makesquare(vector<int>& matchsticks) {
        
        int total_len = 0;
        for(int i = 0 ; i < matchsticks.size() ; i++)
            total_len += matchsticks[i];
        
        if(total_len % 4 || total_len == 0)
            return false;
            
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        
        len_vec.insert(len_vec.begin(), {0,0,0,0});    
        int side_len = total_len / 4;
        
        ans = recur(0, side_len, matchsticks);
        
        
        return ans;
        
    }
};