class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:

        if len(s1) + len(s2) != len(s3):
            return False
        elif not s1 and not s2 and not s3:
            return True

        memo = [[False] * (len(s2)+1) for _ in range(len(s1)+1)]

        memo[0][0] = True
        for i in range(1, len(s1)+1):
            memo[i][0] = memo[i-1][0] and s1[i-1] == s3[i-1]

        for j in range(1, len(s2)+1):
            memo[0][j] = memo[0][j-1] and s2[j-1] == s3[j-1]

        for i in range(1, len(s1)+1):
            for j in range(1, len(s2)+1):
                memo[i][j] = (
                    (memo[i-1][j] and s1[i-1] == s3[i+j-1])
                    or
                    (memo[i][j-1] and s2[j-1] == s3[i+j-1])
                )

        return memo[len(s1)][len(s2)]
