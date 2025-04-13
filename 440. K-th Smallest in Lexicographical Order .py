class Solution:

    def __init__(self):
        self.count = 0

    def findKthNumber(self, n: int, k: int) -> int:
        def dfs(number):
            if number > n:
                return -1
            for i in range(10):
                if 1 <= number+i <= n:
                    self.count += 1
                    if self.count == k:
                        return number+i
                    ret = dfs((number+i)*10)
                    if ret > 0:
                        return ret
            return -1

        return dfs(0)
