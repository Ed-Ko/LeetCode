class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int left = 0;
        int right = 1;
        int ans = 1;
        vector<int> dif_vec;
        
        if(nums.size() == 2)
            return 1;
        
        while(right < nums.size()){
            int cur_dif;
            cur_dif = nums[right] - nums[left];

            if(cur_dif == 0){
                left++;
                right++;
                continue;
            }
            
            if(dif_vec.size() == 0){
                dif_vec.push_back(cur_dif);
                left++;
                right++;
            }
            else{
                if((cur_dif * dif_vec.back()) < 0){
                    left++;
                    right++;
                    dif_vec.push_back(cur_dif);
                }
                else{
                    left = right;
                    right++;
                }
                
            }
            
        }
        
        for(int i = 0 ; i < dif_vec.size() ; i++)
            cout << dif_vec[i] << " ";
        cout << endl;
        
        cout << left << " " << right << endl;
        
        ans = dif_vec.size() + 1;
        
        return ans;
        
    }
};