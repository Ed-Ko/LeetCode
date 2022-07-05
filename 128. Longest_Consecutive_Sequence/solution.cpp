class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> dict;
        
        if(nums.size() == 0)
            return 0;
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(dict.find(nums[i]) == dict.end())
                dict[nums[i]] = 1;
            else
                dict[nums[i]]++;
        }
        
        int ans = 1;
        int cur_max = 1;
        auto pre = dict.begin();
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            /*
            cout << " ===== " << endl;
            cout << "pre : " << pre->first << " " << pre->second << endl;
            cout << "cur : " << it->first << " " << it->second << endl;
            cout << "cur_max : " << cur_max << endl;
            cout << " ===== " << endl;
            */
            if(it == dict.begin())
                continue;
            if(it->first != pre->first + 1){
                ans = max(ans,cur_max);
                cur_max = 1;
            }
                
            else{
                cur_max++;
                
            }
            pre++;
        }
        if(cur_max > ans)
            ans = cur_max;
        return ans;
    }
};