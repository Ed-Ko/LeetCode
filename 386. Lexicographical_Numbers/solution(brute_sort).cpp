class Solution {
public:
    
    vector<int> lexicalOrder(int n) {
        
        vector<int> ans;
        vector<string> buf;
        
        for(int i = 1 ; i <= n ; i++){
            string cur_str = to_string(i);
            buf.push_back(cur_str);
        }
        
        sort(buf.begin(), buf.end());
        
        for(int i = 0 ; i < buf.size() ; i++){
            ans.push_back(stoi(buf[i]));
        }
        
        
        return ans;
        
    }
};