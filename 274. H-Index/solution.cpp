class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        sort(citations.begin(), citations.end());
        int max_h = 0;
        
        for(int i = citations.size() - 1 ; i >= 0 ; i--){
            int cur_h = i + 1;
            int check = 1;
            for(int j = 0 ; j <= i ; j++){
                if(citations[citations.size() - 1 - j] < cur_h){
                    check = 0;
                    break;
                }
            }
            for(int j = 0 ; j < citations.size() - cur_h ; j++){
                if(citations[j] > cur_h){
                    check = 0;
                    break;
                }
            }
            if(check){
                max_h = cur_h;
                break;
            }
            
        }
        
        
        return max_h;
    }
};