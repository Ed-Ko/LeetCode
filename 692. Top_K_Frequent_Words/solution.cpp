class Solution {
public:
    
    static bool comp(pair<string,int>& first, pair<string,int>& second){
        if(first.second == second.second)
            return first.first < second.first;
        return first.second > second.second;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        
        map<string, int> dict;
        
        for(int i = 0 ; i < words.size() ; i++)
            dict[words[i]]++;
        
        vector<pair<string,int>> vec;
        for(auto it = dict.begin() ; it != dict.end() ; it++)
            vec.push_back(make_pair(it->first, it->second));
        
        sort(vec.begin(), vec.end(), comp);    
        
        vector<string> ans;
        for(int i = 0 ; i < k ; i++)
            ans.push_back(vec[i].first);
        
        return ans;
    }
};