class Solution {
public:
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        int ans = 0;
        
        int max_atk = 0;
        for(int i = 0 ; i < properties.size() ; i++)
            max_atk = max(max_atk, properties[i][0]);
        
        int max_def[max_atk + 2];
        memset(max_def, 0, sizeof(max_def));
        
        for(int i = 0 ; i < properties.size() ; i++)
            max_def[properties[i][0]] = max(max_def[properties[i][0]], properties[i][1]);
        
        for(int i = max_atk ; i >= 0 ; i--)
            max_def[i] = max(max_def[i], max_def[i + 1]);
        
        for(int i = 0 ; i < properties.size() ; i++){
            if(properties[i][1] < max_def[properties[i][0] + 1])
                ans++;
        }
        
        
        return ans;
        
    }
};