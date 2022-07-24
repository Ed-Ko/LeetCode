class Solution {
public:
    
    vector<vector<string>> ans;
    
    void recur(string s, vector<string> cur_list, int idx){
        
        if(idx == s.length())
            ans.push_back(cur_list);
        
        for(int i = 1 ; idx + i - 1 < s.length() ; i++){
            string cur_sub = s.substr(idx, i);
            
            int check = 1;
            int left = 0;
            int right = cur_sub.length() - 1;
            while(left <= right){
                if(cur_sub[left] != cur_sub[right]){
                    check = 0;
                    break;
                }
                left++;
                right--;
            }
            if(check){
                cur_list.push_back(cur_sub);
                recur(s, cur_list, idx + i);
                cur_list.pop_back();
            }
            
            
        }
        
        
        return;
    }
     
    vector<vector<string>> partition(string s) {
        
        vector<string> start;
        
        recur(s, start, 0);
        
        return ans;
        
    }
};