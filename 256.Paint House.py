class Solution:
    def minCost(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0

        house_num = len(costs)
        coler_num = len(costs[0])

        dp = [[-1 for _ in range(coler_num)] for _ in range(house_num)]

        for coler in range(coler_num):
            dp[0][coler] = costs[0][coler]

        for house in range(1, house_num):
            for coler in range(coler_num):
                dp[house][coler] = min(dp[house-1][(coler+1)%coler_num], dp[house-1][(coler+2)%coler_num]) + costs[house][coler]

        return min(dp[-1])
