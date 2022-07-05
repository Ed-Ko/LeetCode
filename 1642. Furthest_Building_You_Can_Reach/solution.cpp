class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int i = 0;
        
        priority_queue<int> pq;
        
        for(i = 0 ; i < heights.size() - 1 ; i++){
            if(heights[i] < heights[i+1]){
                
                // check brick
                
                bricks = bricks - (heights[i+1] - heights[i]);
                pq.push(heights[i+1] - heights[i]);
                
                if(bricks < 0){
                    bricks += pq.top();
                    pq.pop();
                    ladders--;
                }
            }
            if(ladders < 0)
                break;
        }
        
        
        return i;
    }
};