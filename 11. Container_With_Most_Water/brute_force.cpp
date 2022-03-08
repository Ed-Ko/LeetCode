class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = (height.size() - 1);
        int left = 0;
        int max_size = 0;

        for(int i = 0 ; i < height.size() ; i++){
            for(int j = 0 ; j < height.size() ; j++){
                if(i < j && (max_size < (min(height[i],height[j]) * (j-i))))
                    max_size = (min(height[i],height[j]) * (j-i));
                
            }
        }
        return max_size;
    }
};