class Solution {
public:
    /*
    int recur(vector<int>& arr, int cur_remain, int end_idx){
        
        int cur_res = 0;
        
        for(int i = 0 ; i < end_idx ; i++){
            
        }
        
    }
    */
    
    int numFactoredBinaryTrees(vector<int>& arr) {
        
        sort(arr.begin(), arr.end());
        
        map<int,long long> dict;
        dict[arr[0]] = 1;
        
        for(int i = 1 ; i < arr.size() ; i++){
            
            long long cur_count = 1;
            for(auto it = dict.begin() ; it != dict.end() ; it++){
                
                if(arr[i] % it->first == 0 && dict.find(arr[i] / it->first) != dict.end())
                    cur_count += (it->second * dict[arr[i] / it->first]);
                
            }
            dict[arr[i]] = cur_count;
        }
        
        int ans = 0;
        int limit = 1000000000 + 7;
        
        for(auto it = dict.begin() ; it != dict.end() ; it++)
            ans = (ans + it->second) % limit;
        
        
        return ans;
        
    }
};