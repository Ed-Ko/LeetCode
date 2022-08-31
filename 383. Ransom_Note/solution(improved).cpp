class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> ran_map;
        
        for(int i = 0 ; i < ransomNote.length() ; i++)
            ran_map[ransomNote[i]]++;
        
        for(int i = 0 ; i < magazine.length() ; i++)
            ran_map[magazine[i]]--;
        
        for(auto it = ran_map.begin() ; it != ran_map.end() ; it++){
            if(it->second > 0)
                return false;
        }
        
        return true;
        
    }
};