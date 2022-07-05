class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int ans = ratings.size();
        int i = 1;
        while(i < ratings.size()){
            
            if(ratings[i] == ratings[i-1]){
                i++;
                continue;
            }
                
            
            int incre = 0;
            while(ratings[i] > ratings[i-1]){
                incre++;
                ans += incre;
                i++;
                if(i == ratings.size())
                    return ans;
            }
            
            int decre = 0;
            while(i < ratings.size() && ratings[i] < ratings[i-1]){
                decre++;
                ans += decre;
                i++;
            }
            ans -= min(incre, decre);
        }
        return ans;
    }
};