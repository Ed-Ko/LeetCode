class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        unordered_map<int,int> dict1;
        unordered_map<int,int> dict2;
        
        for(int i = 0 ; i < nums1.size() ; i++)
            dict1[nums1[i]]++;
        
        for(int i = 0 ; i < nums2.size() ; i++)
            dict2[nums2[i]]++;
        
        if(dict1.size() > dict2.size()){
            for(auto it = dict1.begin() ; it != dict1.end() ; it++){
                if(dict2.find(it->first) != dict2.end())
                    for(int j = 0 ; j < min(it->second, dict2[it->first]) ; j++)
                        ans.push_back(it->first);
            }
        }
        else{
            for(auto it = dict2.begin() ; it != dict2.end() ; it++){
                if(dict1.find(it->first) != dict1.end())
                    for(int j = 0 ; j < min(it->second, dict1[it->first]) ; j++)
                        ans.push_back(it->first);
            }
        }
        
        return ans;
    }
};