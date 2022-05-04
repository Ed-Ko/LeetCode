class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        
        if(people.size() < 2)
            return people;
        
        vector<vector<int>> ans;
        
        map<int, vector<int>>dict;
        
        for(int i = 0 ; i < people.size() ; i++){
            
            int height = people[i][0];
            int priority = people[i][1];
            
            dict[height].push_back(priority);
            
        }
        
        for(auto it = dict.rbegin() ; it != dict.rend() ; it++){
            
            sort(it->second.begin(), it->second.end());
            
            for(int i = 0 ; i < it->second.size() ; i++){
                vector<int> tmp;
                tmp.push_back(it->first);
                tmp.push_back(it->second[i]);
                ans.insert(ans.begin() + it->second[i], tmp);
            }
            
        }
        
        
        
        ///for(int i = 0 ; i < ans.size() ; i++){
        ///    cout << "[" << ans[i][0] << " " << ans[i][1] << "]" << " ";
        ///}
        
        return ans;
    }
};