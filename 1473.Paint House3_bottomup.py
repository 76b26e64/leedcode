class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:

        MAX_COST = 1000001
        memo = [[[MAX_COST] * n for _ in range(target+1)] for _ in range(m)]

        for color in range(1, n+1):
            if houses[0] == color:
                memo[0][1][color-1] = 0
            elif houses[0] == 0:
                memo[0][1][color-1] = cost[0][color-1]

        for house in range(1, m):
            for neighborhoods in range(1, min(target, house+1)+1):
                for color in range(1, n+1):
                    if houses[house] != 0 and color != houses[house]:
                        continue

                    prev_cost_min = MAX_COST
                    for prev_color in range(1, n+1):
                        if prev_color != color:
                            prev_cost_min = min(prev_cost_min, memo[house-1][neighborhoods-1][prev_color-1])
                        else:
                            prev_cost_min = min(prev_cost_min, memo[house-1][neighborhoods][prev_color-1])

                    cost_to_paint = 0 if houses[house] != 0 else cost[house][color-1]
                    memo[house][neighborhoods][color-1] = prev_cost_min + cost_to_paint

        answer = MAX_COST
        for color in range(1, n+1):
            answer = min(answer, memo[m-1][target][color-1])

        return -1 if answer == MAX_COST else answer
