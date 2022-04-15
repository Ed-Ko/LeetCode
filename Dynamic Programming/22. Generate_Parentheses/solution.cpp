class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;

        vector<vector<string>> table;

        vector<string> first;
        first.push_back("()");
        table.push_back(first);

        if(n == 1)
            ans = table[0];
        else{
            int i = 2;
            while(i <= n){

                vector<string> buf;
                table.push_back(buf);

                for(int j = 0 ; j < table[i-2].size() ; j++){
                    string tmp_str = table[i-2][j];
                    for(int k = 0 ; k < tmp_str.length() ; k++){
                        for(int l = k + 1 ; l <= tmp_str.length() ; l++){
                            string new_str = tmp_str;
                            new_str.insert(k,"(");
                            new_str.insert(l,")");
                            if(!count(table[i-1].begin(), table[i-1].end(), new_str))
                                table[i-1].push_back(new_str);
                        }
                    }
                }
                i++;
            }
        }
        
        ans = table[n-1];
        return ans;
        
        
    }
};