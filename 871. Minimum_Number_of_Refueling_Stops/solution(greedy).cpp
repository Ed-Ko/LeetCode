class Solution {
public:
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int min_sta = 0;
        
        priority_queue<int> pq;
        
        if(target <= startFuel)
            return 0;
        
        int cur_fuel = startFuel;
        int i = 0;
        while(cur_fuel < target){
    
            while(i < stations.size() && cur_fuel >= stations[i][0]){
                pq.push(stations[i][1]);
                i++;
            }
            
            if(pq.empty())
                return -1;
            
            cur_fuel += pq.top();
            pq.pop();
            
            min_sta++;
                
        }
        
        return min_sta;    
    }
};