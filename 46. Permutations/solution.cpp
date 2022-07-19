class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
            
        vector<vector<int>> ans;
        
        if(nums.size() == 1){
            ans.push_back(nums);
            return ans;
        }
            
        
        
        queue<vector<int>> q;
        vector<int> tmp;
        tmp.push_back(nums[0]);
        q.push(tmp);
        
        for(int i = 1 ; i < nums.size() ; i++){
            
            vector<vector<int>> cur_ma;
            while(!q.empty()){
                cur_ma.push_back(q.front());
                q.pop();
            }
            
            for(int j = 0 ; j < cur_ma.size() ; j++){
                for(int k = 0 ; k <= cur_ma[j].size() ; k++){
                    vector<int> cur_vec = cur_ma[j];
                    cur_vec.insert(cur_vec.begin() + k, nums[i]);
                    q.push(cur_vec);
                }
                
            }
            
            if(i == nums.size() - 1){
                while(!q.empty()){
                    ans.push_back(q.front());
                    q.pop();
                }
                //cout << endl;
            }
            
        }
        
        return ans;
    }
};