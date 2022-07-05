class Solution {
public:
    
    int maxScore(vector<int>& cardPoints, int k) {
        
        int sum = 0;
        int tmp_sum = 0;
        
        for(int i = 0 ; i < k ; i++)
            tmp_sum += cardPoints[i];
        
        sum = tmp_sum;
        
        for(int i = 0 ; i < k ; i++){
            tmp_sum += cardPoints[cardPoints.size() - 1 - i];
            tmp_sum -= cardPoints[k - 1 - i];
            
            if(tmp_sum > sum)
                sum = tmp_sum;
            
        }
        
        return sum;
        
    }
};