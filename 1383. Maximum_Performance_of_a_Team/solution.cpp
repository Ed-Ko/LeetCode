class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        
        int limit = 1000000000 + 7;
        
        vector<vector<int>> engineer;
        
        for(int i = 0 ; i < speed.size() ; i++)
            engineer.push_back({efficiency[i], speed[i]});
        
        sort(engineer.rbegin(), engineer.rend());
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long long speed_sum = 0;
        long long ans = 0;
        for(int i = 0 ; i < engineer.size() ; i++){
            
            
            pq.push(engineer[i][1]);
            speed_sum += engineer[i][1];
            
            if(pq.size() > k){
                speed_sum -= pq.top();
                pq.pop();
            }
            ans = max(ans, speed_sum * engineer[i][0]);
        }
        
        return ans % limit;
        
    }
};