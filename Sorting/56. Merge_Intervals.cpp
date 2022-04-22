class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        
        int cur_idx = 0;
        int right_idx = 1;
        int left_num = intervals[cur_idx][0];
        int right_num = intervals[cur_idx][1];
        while(right_idx < intervals.size()){
            //cout << right_num << " " << intervals[right_idx][0] << endl;
            if(right_num >= intervals[right_idx][0]){
                right_num = max(intervals[right_idx][1], right_num);
                right_idx++;
            }
            else{
                
                vector<int> tmp;
                tmp.push_back(left_num);
                tmp.push_back(right_num);
                ans.push_back(tmp);
                cur_idx = right_idx;
                right_idx++;
                left_num = intervals[cur_idx][0];
                right_num = intervals[cur_idx][1];
                
                
            }

        }
        
        vector<int> tmp2;
        tmp2.push_back(left_num);
        tmp2.push_back(right_num);
        
        if(find(ans.begin(), ans.end(), tmp2) == ans.end())
            ans.push_back(tmp2);
        
        return ans;
        
    }
};