class Solution {
public:
    int maxArea(vector<int>& height) {
        int right = (height.size() - 1);
        int left = 0;
        int max_size = 0;
        ///int max_left = 0;
        ///int max_right = (height.size() - 1);

        while(left < right){
            ///cout << height[left] << " " << height[left+1] << " ===== " << height[right] << " " << height[right-1] << endl;
            ///cout << min(height[left],height[right]) << endl;
            int cur_size = ((right - left) * min(height[left],height[right]));
            if(max_size < cur_size)
                max_size = cur_size;
            

            ///if((right - 1) >= 0 && height[right - 1] > height[right] && (min(height[left],height[right]) > min(height[left],height[right - 1])))
            ///    right--;
            ///if((left + 1) < height.size() && height[left + 1] > height[left] && (min(height[left],height[right]) > min(height[left + 1],height[right])))
            ///    left++;

            if(height[left] < height[right])
                left++;
            else
                right--;

        }
        return max_size;
    }
};