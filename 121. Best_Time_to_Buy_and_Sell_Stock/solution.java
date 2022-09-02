class Solution {
    public int maxProfit(int[] prices) {
        
        int min_price = Integer.MAX_VALUE;
        int max_price = 0;
        
        for(int i = 0 ; i < prices.length ; i++){
            min_price = Math.min(min_price, prices[i]);
            max_price = Math.max(max_price, prices[i] - min_price);
        }
            
        return max_price;
        
        
    }
}