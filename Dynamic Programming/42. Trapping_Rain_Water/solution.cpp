class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;

        int left_max[height.size()];
        int max_left = height[0];
        int right_max[height.size()];
        int max_right = height[height.size()-1];

        for(int i = 1 ; i < height.size() ; i++){
            max_left = max(max_left, height[i]);
            left_max[i] = max_left;
        }

        for(int i = height.size()-2 ; i >= 0 ; i--){
            max_right = max(max_right, height[i]);
            right_max[i] = max_right;

        }

        for(int i = 1 ; i < height.size() - 1 ; i++){
            //cout << "min : " << min(left_max[i], right_max[i]) << endl;
            //cout << "add : " << (min(left_max[i], right_max[i]) - height[i]) << " " << i << endl;
            ans += (min(left_max[i], right_max[i]) - height[i]);
        }
        return ans;
    }
};