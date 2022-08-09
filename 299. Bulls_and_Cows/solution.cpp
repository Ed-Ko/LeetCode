class Solution {
public:
    string getHint(string secret, string guess) {
        
        map<int,vector<int>> secret_dict;
        map<int,vector<int>> guess_dict;
        
        for(int i = 0 ; i < secret.length() ; i++)
            secret_dict[secret[i]].push_back(i);
        
        for(int i = 0 ; i < guess.length() ; i++)
            guess_dict[guess[i]].push_back(i);
        
        int bull = 0;
        int cow = 0;
        
        for(auto it = guess_dict.begin() ; it != guess_dict.end() ; it++){
            if(secret_dict.find(it->first) != secret_dict.end()){
                int cur_bull = 0;
                for(int i = 0 ; i < it->second.size() ; i++){
                    for(int j = 0 ; j < secret_dict[it->first].size() ; j++){
                        if(secret_dict[it->first][j] == it->second[i])
                            cur_bull++;
                    }
                }
                bull += cur_bull;
                if(secret_dict[it->first].size() - cur_bull > 0 && it->second.size() - cur_bull > 0)
                    cow = cow + min(secret_dict[it->first].size() - cur_bull, it->second.size() - cur_bull);
            }
            
        }
        
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;
    }
};