class Solution {
public:
    
    vector<int> recur(int n, int multi){
        
        vector<int> cur_vec;
        
        for(int i = 9 ; i >= 0 ; i--){
            
            if(i == 0 && multi == 0)
                break;
            
            int cur_num = (multi * 10) + i;
            
            vector<int> cur_return;
            
            if(cur_num * 10 <= n)
                cur_return = recur(n, cur_num);
            

            cur_vec.insert(cur_vec.begin(), cur_return.begin(), cur_return.end());
            
            if(cur_num <= n)
                cur_vec.insert(cur_vec.begin(), cur_num);
        }
        
        return cur_vec;
    }
    
    
    vector<int> lexicalOrder(int n) {
        
        return recur(n, 0);
        
    }
};