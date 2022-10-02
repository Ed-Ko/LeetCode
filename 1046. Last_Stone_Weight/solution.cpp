class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;
        for(int i = 0 ; i < stones.size() ; i++)
            pq.push(stones[i]);
        
        while(pq.size() > 1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            if(abs(first - second) != 0)
                pq.push(abs(first - second));
            
        }
        
        return pq.size() == 1 ? pq.top() : 0;
        
    }
};