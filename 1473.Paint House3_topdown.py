class Solution:
    def minCost(self, houses: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:

        memo = [[[-1] * 21 for _ in range(100)] for _ in range(100)]
        MAX_COST = 1000001

        def findMinCost(houses, cost, target_count, curr_index, neighborhood_count, prev_coler):

            if curr_index == len(houses):
                return 0 if neighborhood_count == target_count else MAX_COST

            if neighborhood_count > target_count:
                return MAX_COST

            if memo[curr_index][neighborhood_count][prev_coler] != -1:
                return memo[curr_index][neighborhood_count][prev_coler]

            min_cost = MAX_COST
            if houses[curr_index] != 0:
                new_neighborhood_count = neighborhood_count  + (houses[curr_index] != prev_coler)
                min_cost = findMinCost(houses, cost, target, curr_index+1, new_neighborhood_count, houses[curr_index])
            else:
                total_colors = len(cost[0])
                for color in range(1, total_colors+1):
                    new_neighborhood_count = neighborhood_count  + (color != prev_coler)
                    curr_cost = cost[curr_index][color-1] + findMinCost(houses, cost, target, curr_index+1, new_neighborhood_count, color)
                    min_cost = min(min_cost, curr_cost)

            memo[curr_index][neighborhood_count][prev_coler] = min_cost
            return min_cost

        answer = findMinCost(houses, cost, target, 0, 0, 0)
        return -1 if answer == MAX_COST else answer

        '''
        #dp : houses
        #dp[] : colerは 1-nなので、0-nの配列を作る
        dp_cost  = [[float('inf')] * (n+1) for _ in range(m)] #その色で塗った時のコスト
        dp_group = [[float('inf')] * (target+1) for _ in range(m)] #neighborを考慮したコスト

        #ininialze house[0]
        if houses[0] != 0:
            dp_cost[0][house] = 0  # already painted, cost is 0
        else:
            for color in range(1, n+1):
                dp_cost[0][color] = cost[0][color-1]

        for color in range(1, n+1):
            dp_group[0][color] = 1

        for i in range(1, m):
            # House is already painted
            if houses[i] != 0:
                current_color = houses[i]
                for prev_color in range(1, n+1):
                    dp_cost[i][current_color] = dp_cost[i-1][prev_color]
                    if current_color != prev_color:
                        dp_group[i][current_color] = dp_group[i-1][prev_color] + 1
                    else:
                        dp_group[i][current_color] = dp_group[i-1][prev_color]


            else:
                for current_color in range(1, n+1):
                    for prev_color in range(1, n+1):




            answer += min(dp[i])

        return answer
        '''

        '''
        dp = [[[float('inf') for _ in range(n)] for _ in range(target)] for _ in range(m)]

        if houses[0] != 0:
            dp[0][0][houses[0]-1] = 0
        else:
            for color in range(n):
                dp[0][0][color] = cost[0][color]

        for house in range(1, m):
            for neighbor in range(target):
                for color in range(n):
                    if houses[house] != 0:
                        if houses[house]-1 == color:
                            if dp[house-1][neighbor][color] != float('inf'):
                                dp[house][neighbor][color] = min(dp[house][neighbor][color], dp[house-1][neighbor][color])
                        else:
                            if neighbor < (target-1):
                                tmp = dp[house-1][neighbor][houses[house]-1]
                                dp[house-1][neighbor][houses[house]-1] = float('inf')
                                dp[house][neighbor+1][houses[house]-1] = min(dp[house][neighbor+1][houses[house]-1], min(dp[house-1][neighbor]))
                                dp[house-1][neighbor][houses[house]-1] = tmp
                    else:
                        min_index = dp[house-1][neighbor].index(min(dp[house-1][neighbor]))
                        if color == min_index:
                            dp[house][neighbor][color] = min(dp[house][neighbor][color], dp[house-1][neighbor][color] + cost[house][color])
                        else:
                            if neighbor < (target-1):
                                tmp = dp[house-1][neighbor][color]
                                dp[house-1][neighbor][color] = float('inf')
                                dp[house][neighbor+1][color] = min(dp[house][neighbor+1][color], min(dp[house-1][neighbor]) + cost[house][color])
                                dp[house-1][neighbor][color] = tmp

        print(dp)
        answer = min(dp[-1][target-1])
        return -1 if answer == float('inf') else answer
        '''
