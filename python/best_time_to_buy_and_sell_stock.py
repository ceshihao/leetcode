class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        buy_price = prices[0]
        profit = 0
        for i in range(len(prices)):
            if prices[i] - buy_price > profit:
                profit = prices[i] - buy_price
            elif prices[i] < buy_price:
                buy_price = prices[i]
        return profit