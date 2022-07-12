class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        int unit_len = words[0].length();
        int total_len = unit_len * words.size();
        vector<int> ans;
        
        if(total_len > s.length())
            return ans;
        
        unordered_map<string,int> dict;
        for(int j = 0 ; j < words.size() ; j++){
            if(dict.find(words[j]) != dict.end())
                dict[words[j]]++;
            else
                dict[words[j]] = 1;
        }
        
        for(int i = 0 ; i <= s.length() - total_len ; i++){
            
            unordered_map<string,int> umap;
            
            //cout << "cur_word : " << cur_word << endl;
            for(int j = i ; j < i + total_len ; j += unit_len){
                string sub_str = s.substr(j, unit_len);
                //cout << "sub_str : " << sub_str << endl;
            
                if(umap.find(sub_str) != umap.end())
                    umap[sub_str]++;
                else
                    umap[sub_str] = 1;
                
            }
            if(umap == dict)
                ans.push_back(i);
        }
        
        return ans;
    }
};