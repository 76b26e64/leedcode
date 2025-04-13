class Solution:
    def minTimeToReach(self, moveTime: List[List[int]]) -> int:
        max_col = len(moveTime[0])
        max_row = len(moveTime)

        dp = [[0 for _ in range(max_col)]for _ in range(max_row)]

        dp[0][0] = moveTime[0][0]
        for i in range(1, max_col):
            dp[0][i] = max(dp[0][i-1]+1, moveTime[0][i-1]+1) 
        
        for i in range(1, max_row):
            dp[i][0] = max(dp[i-1][0]+1, moveTime[i-1][0]+1) 
        
        for i in range(1, max_row):
            for j in range(j, max_col):
                dp[i][j] = max(dp[i][j-1]+1, dp[i-1][j]+1)

        return dp[-1][-1] 