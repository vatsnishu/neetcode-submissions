class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        
        min_price=100
        max_profit=0
  
        for i in range(len(prices)):
            cur_profit=prices[i]-min_price
            if cur_profit>max_profit:
                max_profit=cur_profit

            if min_price>prices[i]:    
                min_price=prices[i]
                
        return max_profit