class Solution {
public:
    
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        sort(tokens.begin(), tokens.end());
        
        int up_idx = 0;
        int down_idx = tokens.size();
        int cur_pow = power;
        int score = 0;
        
        while(up_idx < down_idx){            
            if(cur_pow >= tokens[up_idx]){
                cur_pow -= tokens[up_idx];
                score++;
                up_idx++;
                
            }
            else if(score > 0 && down_idx > up_idx + 1){
                down_idx--;
                cur_pow += tokens[down_idx];
                score--;
            }
            else
                break;
        }
        
        return score;
        
    }
};