class Solution {
public:
    int minDeletions(string s) {
        map<char,int> dict;
        map<int,int> res;
        int ans = 0;
        for(int i = 0 ; i < s.length() ; i++){
            //cout << s[i] << " ";
            if(dict.find(s[i]) != dict.end())
                dict[s[i]]++;
            else
                dict[s[i]] = 1;
        }
        for(auto it = dict.begin() ; it != dict.end() ; it++){
            //cout << it->first << " " << it->second << endl;
            if(res.find(it->second) != res.end())
                res[it->second]++;
            else
                res[it->second] = 1;
        }
        int buf = 0;
        for(auto it = res.rbegin() ; it != res.rend() ; it++){
            //cout << it->first << " " << it->second << endl;
            it->second += buf;
            ans = ans + it->second-1;
            buf = it->second-1;
            if(res.find(it->first - 1) == res.end() && it->second-1 >= 1 && it->first-1 > 0)
                res[it->first - 1] = 0;
            it->second = 1;

        }
        //for(auto it = res.rbegin() ; it != res.rend() ; it++){
        //   cout << it->first << " " << it->second << endl;
        //}
        //cout << endl;
        return ans;
    }
};