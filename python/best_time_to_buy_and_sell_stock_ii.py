class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        profit = 0
        if len(prices) == 0:
            return profit
        max_price = prices[0]
        for price in prices:
            if (price < max_price):
                max_price = price
            elif (price > max_price):
                profit += price - max_price
                max_price = price
        return profit