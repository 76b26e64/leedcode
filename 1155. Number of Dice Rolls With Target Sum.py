class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        memo = [[0] * target for _ in range(n)]

        for i in range(k):
            if i < target:
                memo[0][i] = 1

        for dice_no in range(1, n):
            begin = False
            for last_i in range(dice_no-1, target):
                if memo[dice_no-1][last_i] != 0:
                    begin = True
                    for offset in range(1, k+1):
                        if (last_i+offset) < target:
                            memo[dice_no][last_i+offset] += memo[dice_no-1][last_i]
                        else:
                            break
                else:
                    if begin:
                        break

        return memo[n-1][target-1] % 1000000007
