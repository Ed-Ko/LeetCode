int comp(string a, string b){
        string ab = a.append(b);
        string ba = b.append(a);
        
        return ab > ba ? 1 : 0;
}
class Solution {
public:
    
    string largestNumber(vector<int>& nums) {
        vector<string> tmp;
        string ans;
        
        for(int i = 0; i < nums.size() ; i++)
            tmp.push_back(to_string(nums[i]));
        
        sort(tmp.begin(), tmp.end(), comp);
        
        for(int i = 0 ; i < tmp.size() ; i++)
            ans += tmp[i];
        
        if(ans[0] == '0')
            return "0";
        
        return ans;
    }
};