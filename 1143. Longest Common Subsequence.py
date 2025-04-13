class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:

        text1_len = len(text1)
        text2_len = len(text2)
        memo = [[0] * (text2_len+1) for _ in range(text1_len+1)]
        for col in reversed(range(text2_len)):
            for row in reversed(range(text1_len)):
                if text1[row] == text2[col]:
                    memo[row][col] = 1 + memo[row+1][col+1]
                else:
                    memo[row][col] = max(memo[row+1][col],memo[row][col+1])

        return memo[0][0]
