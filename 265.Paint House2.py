class Solution:
    def minCostII(self, costs: List[List[int]]) -> int:
        if not costs:
            return 0

        house_num = len(costs)
        coler_num = len(costs[0])

        pervious_costs = costs[0]
        current_costs  = costs[0].copy()
        for house in range(1, house_num):
            for color in range(coler_num):
                cost = pervious_costs[color]
                pervious_costs[color] = float('inf')
                current_costs[color] = min(pervious_costs) + costs[house][color]
                pervious_costs[color] = cost

            pervious_costs = current_costs.copy()

        return min(current_costs)
