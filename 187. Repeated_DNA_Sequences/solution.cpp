class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        map<string,int> record;
        
        vector<string> ans;
        
        for(int i = 0 ; i + 10 <= s.length() ; i++){
            string cur_str = s.substr(i, 10);    
            if(record[cur_str] == 1){
                ans.push_back(cur_str);
                record[cur_str]++;
            } 
            record[cur_str]++;
        }
        
        return ans;
    }
};