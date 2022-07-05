class Solution {
public:
    
    static bool compare(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        
        sort(courses.begin(), courses.end(), compare);
        
        priority_queue<int> pq;
        
        int total_time = 0;
        
        for(int i = 0 ; i < courses.size() ; i++){
            
            //cout << total_time + courses[i][0] << " " << courses[i][1] << endl;
                
            if(total_time + courses[i][0] <= courses[i][1]){
                pq.push(courses[i][0]);
                total_time += courses[i][0];
            }
            
            else if(!pq.empty() && pq.top() > courses[i][0]){
                total_time = total_time - pq.top() + courses[i][0];
                pq.pop();
                pq.push(courses[i][0]);
            }
        }
        
        return pq.size();
        
    }
};