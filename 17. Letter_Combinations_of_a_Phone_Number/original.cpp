class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> ans;

        map<char, vector<char>> dict;
        dict['2'] = {'a','b','c'};
        dict['3'] = {'d','e','f'};
        dict['4'] = {'g','h','i'};
        dict['5'] = {'j','k','l'};
        dict['6'] = {'m','n','o'};
        dict['7'] = {'p','q','r','s'};
        dict['8'] = {'t','u','v'};
        dict['9'] = {'w','x','y','z'};

        if(digits.length() >= 1){
            for(int i = 0 ; i < dict[digits[0]].size() ; i++){
                string buf = "";
                buf += dict[digits[0]][i];   
                ans.push_back(buf);     
            }
        }

        if(digits.length() >= 2){
            int size_now = ans.size();
            for(int i = 0 ; i < size_now ; i++){
                string str_now = ans[0];
                ans.erase(ans.begin());
                for(int j = 0; j < dict[digits[1]].size() ; j++){
                    ans.push_back(str_now + dict[digits[1]][j]);
                }
            }
        }

        if(digits.length() >= 3){
            int size_now = ans.size();
            for(int i = 0 ; i < size_now ; i++){
                string str_now = ans[0];
                ans.erase(ans.begin());
                for(int j = 0; j < dict[digits[2]].size() ; j++){
                    ans.push_back(str_now + dict[digits[2]][j]);
                }
            }
        }

        if(digits.length() >= 4){
            int size_now = ans.size();
            for(int i = 0 ; i < size_now ; i++){
                string str_now = ans[0];
                ans.erase(ans.begin());
                for(int j = 0; j < dict[digits[3]].size() ; j++){
                    ans.push_back(str_now + dict[digits[3]][j]);
                }
            }
        }
        
        return ans;
        
    }
};