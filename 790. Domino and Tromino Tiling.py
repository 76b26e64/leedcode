class Solution:
    def numTilings(self, n: int) -> int:
        dp = [0] * n + 1

        dp[1] = 1
        dp[2] = 2
        dp[3] = 5

        for i range(4, n):
            if i % 3 == 1:
                dp[n] = dp[n-1] + 2
            elif i % 3 == 2:

            else

        return dp[]
