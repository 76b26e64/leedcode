class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        n = len(prices)
        free = 0
        hold = -prices[0]
        for i in range(1, n):
            tmp = hold
            hold = max(hold, free - prices[i])
            free = max(free, tmp + prices[i] - fee)

        return free
