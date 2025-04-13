class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0
        elif len(prices) == 1:
            return 0

        dp_sold = [0] * len(prices)
        dp_hold = [0] * len(prices)
        dp_cooldown = [0] * len(prices)

        dp_cooldown[0] = 0
        dp_hold[0] = -prices[0]
        dp_sold[0] = 0

        for day in range(1, len(prices)):
            dp_cooldown[day] = max(dp_cooldown[day-1], dp_sold[day-1])
            dp_hold[day] = max(dp_hold[day-1], dp_cooldown[day-1]-prices[day])
            dp_sold[day] = dp_hold[day-1] + prices[day]

        return max(dp_cooldown[len(prices)-1], dp_sold[len(prices)-1])
