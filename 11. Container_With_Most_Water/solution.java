class Solution {
    public int maxArea(int[] height) {
        
        int left = 0;
        int right = height.length - 1;
        
        int ans = 0;
        
        while(left < right){
            
            if(ans < Math.min(height[left], height[right]) * (right - left))
                ans = Math.min(height[left], height[right]) * (right - left);
                
            
            if(height[left] < height[right])
                left++;
            else
                right--;

        }
        
        return ans;
        
    }
}