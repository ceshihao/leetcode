func maxProfit(prices []int, fee int) int {
	cash := 0
	hold := -prices[0]
	for _, price := range prices {
		cash = max(cash, hold+price-fee)
		hold = max(hold, cash-price)
	}
	return cash
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
