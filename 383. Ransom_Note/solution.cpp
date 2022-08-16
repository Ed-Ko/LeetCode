class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        map<char,int> ran_map;
        map<char,int> mag_map;
        
        for(int i = 0 ; i < ransomNote.length() ; i++)
            ran_map[ransomNote[i]]++;
        
        for(int i = 0 ; i < magazine.length() ; i++)
            mag_map[magazine[i]]++;
        
        bool ans = true;
        for(auto it = ran_map.begin() ; it != ran_map.end() ; it++){
            if(mag_map.find(it->first) == mag_map.end() || mag_map[it->first] < it->second){
                ans = false;
                break;
            }
        }
        
        return ans;
        
    }
};