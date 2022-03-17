class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int idx = 0;
        int out = 0;

        ///if(strs.size() == 0)
        ///    return ans;

        while(out == 0){
            char cur_ch = strs[0][idx];
            for(int i = 0 ; i < strs.size() ; i++){
                if(strs[i].size() <= idx){
                    out = 1;
                    break;
                }
                if(strs[i][idx] != cur_ch){
                    out = 1;
                    break;
                }
            }
            if(out == 0)
                ans += cur_ch;
            idx++;
        }

        return ans;
    }
};