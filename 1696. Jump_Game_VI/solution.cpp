class Solution {
public:
    
    int maxResult(vector<int>& nums, int k) {
        
        int ans = 0;
        int dp[nums.size() + 1];
        priority_queue<pair<int,int>> pq;
        pq.push(make_pair(nums[0], 0));
        memset(dp, 0, sizeof(dp));
        dp[0] = nums[0];
        
        for(int i = 1 ; i < nums.size() ; i++){
            while(!pq.empty() && pq.top().second < i - k)
                pq.pop();
            dp[i] = nums[i] + pq.top().first;
            pq.push(make_pair(dp[i], i));
            //cout << dp[i] << " ";
        }
        return dp[nums.size() - 1];
        
    }
};