class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        
        int ans = 0;
        
        sort(verticalCuts.begin(), verticalCuts.end());
        sort(horizontalCuts.begin(), horizontalCuts.end());
        
        int max_ver = verticalCuts[0];
        int max_hor = horizontalCuts[0];
        
        for(int i = 1 ; i < horizontalCuts.size() ; i++){
            if(horizontalCuts[i] - horizontalCuts[i-1] > max_hor)
                max_hor = horizontalCuts[i] - horizontalCuts[i-1];
        }
        if(h - horizontalCuts[horizontalCuts.size()-1] > max_hor)
            max_hor = h - horizontalCuts[horizontalCuts.size()-1];
        
        for(int i = 1 ; i < verticalCuts.size() ; i++){
            if(verticalCuts[i] - verticalCuts[i-1] > max_ver)
                max_ver = verticalCuts[i] - verticalCuts[i-1];
        }
        if(w - verticalCuts[verticalCuts.size()-1] > max_ver)
            max_ver = w - verticalCuts[verticalCuts.size()-1];
        
        long long block = 1e9 + 7;
        
        return (1LL * max_ver * max_hor) % block;
    }
};