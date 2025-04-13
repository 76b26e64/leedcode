class Solution:
    def mincostTickets(self, days: List[int], costs: List[int]) -> int:

        memo = [0] * days[0] + [float('inf')] * ((days[-1]+1) - days[0])
        days_index = 0
        total_cost = 0

        for current_date in range(days[0], days[-1]+1):
            if current_date != days[days_index]:
                memo[current_date] = min(memo[current_date], memo[current_date-1])
                continue

            memo[current_date]                   = min(memo[current_date], memo[current_date-1]+costs[0])
            memo[min(current_date+6, days[-1])]  = min(memo[min(current_date+6, days[-1])],  memo[current_date-1]+costs[1])
            memo[min(current_date+29, days[-1])] = min(memo[min(current_date+29, days[-1])], memo[current_date-1]+costs[2])

            days_index += 1

        return memo[-1]
