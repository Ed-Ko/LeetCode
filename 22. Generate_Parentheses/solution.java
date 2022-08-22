class Solution {
public:
    
    vector<string> ans;
    
    void recur(int left_b, int right_b, string cur_str){
        
        if(left_b == 0 && right_b == 0){
            ans.push_back(cur_str);
            return;
        }
        
        if(left_b > 0){
            string tmp_str = cur_str;
            tmp_str.push_back('(');
            recur(left_b - 1, right_b, tmp_str);
        }
        if(left_b < right_b){
            string tmp_str = cur_str;
            tmp_str.push_back(')');
            recur(left_b, right_b - 1, tmp_str);
        }
        
        
        return ;
        
    }
    
    vector<string> generateParenthesis(int n) {

        string start = "";
        
        recur(n, n, start);
        
        return ans;
    }
};