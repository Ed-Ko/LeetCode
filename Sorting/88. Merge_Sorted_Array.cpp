class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        vector<int> ans;
        
        int idx1 = 0;
        int idx2 = 0;
        
        while(idx1 < m || idx2 < n){
            
            if(idx1 > m && nums1[idx1] == 0){
                idx1++;
                continue;
            }
            

            
            if(idx1 >= m && idx2 < n){
                ans.push_back(nums2[idx2]);
                idx2++;
            }
            else if(idx1 < m && idx2 >= n){
                ans.push_back(nums1[idx1]);
                idx1++;
            }
            else{
                if(nums1[idx1] < nums2[idx2]){
                    ans.push_back(nums1[idx1]);
                    idx1++;
                }
                else{
                    ans.push_back(nums2[idx2]);
                    idx2++;
                }
            }
        }
        
        for(int i = 0 ; i < ans.size() ; i++){
            nums1.erase(nums1.begin());
            nums1.push_back(ans[i]);
        }
        
    }
};