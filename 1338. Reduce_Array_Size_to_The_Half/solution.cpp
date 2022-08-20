class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        map<int,int> dict;
        vector<int> reverse;
        int ans = 0;
        
        for(int i = 0 ; i < arr.size() ; i++)
            dict[arr[i]]++;
        
        for(auto it = dict.begin() ; it != dict.end() ; it++)
            reverse.push_back(it->second);
        
        sort(reverse.begin(), reverse.end());
        
        int counter = 0;
        for(int i = reverse.size() - 1 ; i >= 0 && counter < arr.size() / 2; i--){
            //cout << counter << " " << reverse[i] << endl;
            counter += reverse[i];
            ans++;
        }
        
        return ans;
        
    }
};