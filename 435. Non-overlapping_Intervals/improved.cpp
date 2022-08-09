class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        int ans = 0;
        int max_end = intervals[0][1];
        
        for(int i = 1 ; i < intervals.size() ; i++){
            
            if(intervals[i][0] < max_end){
                max_end = min(intervals[i][1], max_end);
                ans++;
            }
            else
                max_end = intervals[i][1];
            
        }
        
        return ans;        
    }
};