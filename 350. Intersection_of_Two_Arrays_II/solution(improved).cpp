class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> ans;
        
        int dict[1001];
        memset(dict, 0, sizeof(dict));
        
        for(int i = 0 ; i < nums1.size() ; i++)
            dict[nums1[i]]++;
        
        for(int i = 0 ; i < nums2.size() ; i++){
            if(dict[nums2[i]] > 0){
                dict[nums2[i]]--;
                ans.push_back(nums2[i]);
            }
        }
        
        return ans;
        
    }
};