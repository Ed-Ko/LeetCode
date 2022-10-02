class Solution {
public:
    
    bool recur(vector<string>& str_vec, int idx){
        
        if(idx >= str_vec.size())
            return true;
        
        if(str_vec[idx][0] == '0')
            return recur(str_vec, idx + 1);
        
        if(str_vec[idx].substr(0, 3) == "110" && idx + 1 < str_vec.size() && str_vec[idx + 1].substr(0, 2) == "10")
            return recur(str_vec, idx + 2);
        
        if(str_vec[idx].substr(0, 4) == "1110" && idx + 1 < str_vec.size() && str_vec[idx + 1].substr(0, 2) == "10" && idx + 2 < str_vec.size() && str_vec[idx + 2].substr(0, 2) == "10")
            return recur(str_vec, idx + 3);
        
        if(str_vec[idx].substr(0, 5) == "11110" && idx + 1 < str_vec.size() && str_vec[idx + 1].substr(0, 2) == "10" && idx + 2 < str_vec.size() && str_vec[idx + 2].substr(0, 2) == "10" && idx + 3 < str_vec.size() && str_vec[idx + 3].substr(0, 2) == "10")
            return recur(str_vec, idx + 4);
        
        return false;
    }
    
    
    bool validUtf8(vector<int>& data) {
        
        vector<string> str_vec;
        
        for(int i = 0 ; i < data.size() ; i++){
            int cur_int = data[i];
            int divisor = pow(2, 7);
            string cur_str;
            while(divisor > 0){
                if(cur_int < divisor)
                    cur_str.push_back('0');
                else{
                    cur_str.push_back('1');
                    cur_int -= divisor;
                }
                divisor /= 2;
            }
            str_vec.push_back(cur_str);    
        }

        return recur(str_vec, 0);
        
    }
};