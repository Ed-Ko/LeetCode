class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        vector<pair<int,int>> vec;
        vector<int> conf_vec;
        
        sort(intervals.begin(), intervals.end());
        
        for(int i = intervals.size() - 1 ; i >= 0 ; i--){
            //cout << intervals[i][0] << " " << intervals[i][1] << endl;
            int cur_count = 0;
            int check = 1;
            for(int j = 0 ; j < vec.size() ; j++){
                if(intervals[i][1] > vec[j].first){
                    check = 0;
                    cur_count++;
                }
            }
            if(check)
                vec.push_back(make_pair(intervals[i][0], intervals[i][1]));
            conf_vec.push_back(cur_count);
        }
        
        int ans = 0;
        for(int i = 0 ; i < conf_vec.size() ; i++){
            if(conf_vec[i] > 0)
                ans++;
        }
        
        return ans;        
    }
};