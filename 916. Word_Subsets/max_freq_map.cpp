class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<string> ans;
        map<char,int> dict;
        
        for(int i = 0 ; i < words2.size() ; i++){
            map<char,int> tmp;
            string cur_word = words2[i];
            for(int j = 0 ; j < cur_word.length() ; j++)
                tmp[cur_word[j]]++;
            
            for(auto it = tmp.begin() ; it != tmp.end() ; it++){
                if(dict.find(it->first) == dict.end())
                    dict[it->first] = it->second;
                else if(dict[it->first] < it->second)
                    dict[it->first] = it->second;
            }
        }
        
        for(int i = 0 ; i < words1.size() ; i++){
            string cur_word = words1[i];
            map<char,int> cur_map;
            for(int j = 0 ; j < cur_word.length() ; j++)
                cur_map[cur_word[j]]++;
            
            int check1 = 1;
            for(auto it = dict.begin() ; it != dict.end() ; it++){
                if(cur_map.find(it->first) == cur_map.end() || cur_map[it->first] < it->second){
                    check1 = 0;
                    break;
                }
            }
            
            if(check1)
                ans.push_back(cur_word);
                
        }
        
        return ans;
        
    }
};