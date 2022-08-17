class Solution {
public:
    int firstUniqChar(string s) {
        
        unordered_map<char,vector<int>> dict;
        
        for(int i = 0 ; i < s.length() ; i++)
            dict[s[i]].push_back(i);
        
        int tar_idx = s.length();
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            if(it->second.size() <= 1 && tar_idx > it->second[0]){
                //cout << it->first << " ";
                tar_idx = it->second[0];
            }
        }
        
        if(tar_idx == s.length())
            return -1;
        else
            return tar_idx;
            
    }
};