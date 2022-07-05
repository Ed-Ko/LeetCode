class Solution {
public:
    
    static bool compare(string a, string b){
        return a.length() > b.length();
    }
    
    int minimumLengthEncoding(vector<string>& words) {
        
        
        int ans = 0;
        
        sort(words.begin(), words.end(), compare);
        
        unordered_map<string, int> str_map;
        
        for(int i = 0 ; i < words.size() ; i++)
            str_map[words[i]] = 1;
            
        for(int i = 0 ; i < words.size() ; i++){
            string cur_str = words[i];
            
            if(str_map[cur_str] > 0){
                ans = ans + cur_str.length() + 1;
                //cout << cur_str << endl;
                for(int k = cur_str.size() - 1 ; k >= 0 ; k--){
                    string cur_sub = cur_str.substr(k, cur_str.size() - k);
                    str_map[cur_sub] = 0;
                }
                
            }
            
        }
        
        
        return ans;
    }
};