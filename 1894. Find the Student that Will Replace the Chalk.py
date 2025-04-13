class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        n = len(chalk)
        if n == 1:
            return 0

        total = sum(chalk)
        k %= total

        answer = -1
        for i in range(n):
            k -= chalk[i]
            if k < 0:
                answer = i
                break

        return answer
