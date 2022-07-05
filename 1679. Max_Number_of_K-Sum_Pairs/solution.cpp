class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        unordered_map<int, queue<int>> queue_map;
        int ans = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
            queue_map[nums[i]].push(i);
        
        
        
        for(auto it = queue_map.begin() ; it != queue_map.end() ; it++){
            
            if(queue_map.find(k - it->first) != queue_map.end()){
                ///cout << it->first << " " << k - it->first << endl;
                
                while(!it->second.empty() && !queue_map[(k - it->first)].empty()){
                    
                    int flag1 = 0;
                    int flag2 = 0;
                    
                    if(!it->second.empty()){
                        it->second.pop();
                        flag1 = 1;
                    }
                    if(!queue_map[(k - it->first)].empty()){
                        queue_map[(k - it->first)].pop();
                        flag2 = 1;
                    }
                    
                    if(flag1 && flag2)
                        ans++;
                }
            }
        }
        ///cout << endl;
        return ans;
        
    }
};