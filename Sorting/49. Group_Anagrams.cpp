class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string, vector<string>> str_map;
        vector<vector<string>> ans;
        
        for(int i = 0 ; i < strs.size() ; i++){
            string cur_str = strs[i];
            sort(cur_str.begin(), cur_str.end());
            str_map[cur_str].push_back(strs[i]);
        }
        
        for(map<string, vector<string>>::iterator it = str_map.begin() ; it != str_map.end() ; it++){
            vector<string> tmp;
            for(int i = 0 ; i < it->second.size() ; i++){
                tmp.push_back(str_map[it->first][i]);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};