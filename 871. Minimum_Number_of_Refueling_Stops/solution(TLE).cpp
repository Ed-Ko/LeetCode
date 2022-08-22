class Solution {
public:
    
    map<int,int> dict;
    
    int recur(int target, int cur_sta, int cur_fuel, vector<vector<int>>& stations){
            
        int fuel_now = cur_fuel + stations[cur_sta][1];
        //cout << cur_sta << " : " << fuel_now << " " << stations[cur_sta][1] << endl;
        
        if(fuel_now + stations[cur_sta][0] >= target)
            return 1;
        
        int cur_min = INT_MAX - 1;
        
        for(int i = cur_sta + 1 ; i < stations.size() ; i++){
            if(stations[i][0] <= fuel_now + stations[cur_sta][0])
                cur_min = min(cur_min, recur(target, i, fuel_now + stations[cur_sta][0] - stations[i][0], stations));
        }
        
        return cur_min + 1;
    }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        
        int min_sta = INT_MAX;
        
        if(target <= startFuel)
            return 0;
        
        for(int i = 0 ; i < stations.size() ; i++){
            if(stations[i][0] <= startFuel)
                min_sta = min(min_sta, recur(target, i, startFuel - stations[i][0], stations));
        }
        if(min_sta != INT_MAX)
            return min_sta;
        return -1;    
    }
};